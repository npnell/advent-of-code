#ifndef READ_H
#define READ_H

#include <iostream>
#include <fstream>
#include <vector>

template<typename T>
void log(const T &output)
{
    std::cout << output << std::endl;
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

int extract_token(const std::vector<char>::const_iterator &lexeme_begin, const std::vector<char>::const_iterator &forward)
{
    std::string token(lexeme_begin, forward);
    return std::stoi (token);
}

std::vector<int> tokenize_buffer(const std::vector<char> &buffer)
{
    std::vector<char>::const_iterator lexeme_begin = begin(buffer);
    std::vector<char>::const_iterator forward = begin(buffer);
    std::vector<int> tokens;

    if(begin(buffer) != end(buffer)) {
        while(forward != end(buffer)) {
            if(*forward == '\n' || *forward == '\0' || *forward == ' ' || *forward == EOF) {
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

int sweep(const std::vector<int> &depths)
{
    int depth_increments = 0;
    if(begin(depths) != end(depths)) {
        for(auto iter = begin(depths); end(depths) - iter > 1; ++iter) {
            if(*iter < *(iter + 1)) {
                depth_increments = depth_increments + 1;
            }
        }   
    }
    return depth_increments;
}

std::vector<int> grouped_depths(const std::vector<int> &depths)
{
    std::vector<int> sliding_window;
    for(auto iter = begin(depths); end(depths) - iter  > 2; ++iter) {
        sliding_window.push_back(*iter + *(iter + 1) + *(iter + 2));
    }
    return sliding_window;
}

#endif