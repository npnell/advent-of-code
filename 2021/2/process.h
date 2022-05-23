#ifndef READ_H
#define READ_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

typedef enum {FORWARD, UP, DOWN} direction;

typedef struct {
    direction dir;
    int dist;
} command;

template<typename T>
void log(const T &output)
{
    std::cout << output << std::endl;
}

bool isnumeric(const std::string &s)
{
    std::string::const_iterator iter = s.begin();
    while(iter != s.end() && std::isdigit(*iter)) ++iter;
    return !s.empty() && iter == s.end();
}

std::string stolower(const std::string &istr)
{
    std::vector<unsigned char> ovec(istr.size());
    std::transform(istr.begin(), istr.end(), ovec.begin(), 
        [](unsigned char c){ return std::tolower(c); });
    std::string ostr(ovec.begin(), ovec.end());
    return ostr;
}

int read_file(std::vector<char> &buffer, std::string filename)
{
    std::ifstream instream(filename, std::ios::in | std::ios::binary | std::ios::ate);
    if(instream) {
        std::size_t size = instream.tellg();
        instream.seekg(0, std::ios::beg);

        buffer.resize(size);
        instream.read(buffer.data(), size);
        if(!instream) {
            std::cerr << "failed to read file: " + filename + "\n";
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    } else {
        std::cerr << "failed to open file: " + filename + "\n";
        return EXIT_FAILURE;
    }
}

std::string extract_token(const std::vector<char>::const_iterator &lexeme_begin, const std::vector<char>::const_iterator &forward)
{
    std::string token(lexeme_begin, forward);
    return stolower(token);
}

std::vector<std::string> tokenize_buffer(const std::vector<char> &buffer)
{
    std::vector<char>::const_iterator lexeme_begin = begin(buffer);
    std::vector<char>::const_iterator forward = begin(buffer);
    std::vector<std::string> tokens;

    if(begin(buffer) != end(buffer)) {
        while(forward != end(buffer)) {
            if(*forward == ' ' || *forward == '\n' || *forward == '\0' || *forward == EOF) {
                tokens.push_back(extract_token(lexeme_begin, forward));
                lexeme_begin = forward + 1;
            }
            ++forward;
        }
        if(forward != lexeme_begin)
            tokens.push_back(extract_token(lexeme_begin, forward));
    }
    return tokens;
}

std::vector<command> parse(const std::vector<std::string> &buffer)
{
    std::vector<command> commands;
    command c;

    for(std::size_t i = 0; i < buffer.size(); ++i) {
        if(isnumeric(buffer[i + 1])) {
            if(!buffer[i].compare("up")) {
                c.dir = direction::UP;        
            } else if(!buffer[i].compare("down")) {
                c.dir = direction::DOWN;
            } else if(!buffer[i].compare("forward")) {
                c.dir = direction::FORWARD;
            }
            c.dist = std::stoi(buffer[i + 1]);
            commands.push_back(c);
        }
    }
    return commands;
}

void traverse(const std::vector<command> &commands, int &h_pos, int &depth)
{
    for(auto iter = begin(commands); iter != end(commands); ++iter) {
        switch(iter->dir) {
            case direction::FORWARD:    h_pos = h_pos + iter->dist;     break;
            case direction::UP:         depth = depth - iter->dist;     break;
            case direction::DOWN:       depth = depth + iter->dist;     break;
        }
    }
}

void ntraverse(const std::vector<command> &commands, int &h_pos, int &depth, int &aim)
{
    for(auto iter = begin(commands); iter != end(commands); ++iter) {
        switch(iter->dir) {
            case direction::FORWARD:    h_pos = h_pos + iter->dist;
                                        depth = depth + aim*iter->dist;     break;
            case direction::UP:         aim = aim - iter->dist;             break;
            case direction::DOWN:       aim = aim + iter->dist;             break;
        }
    }
}

#endif