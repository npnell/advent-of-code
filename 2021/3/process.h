#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

std::string stolower(const std::string &istr)
{
    std::vector<unsigned char> ovec(istr.size());
    std::transform(istr.begin(), istr.end(), ovec.begin(), 
        [](unsigned char c){ return std::tolower(c); });
    std::string ostr(ovec.begin(), ovec.end());
    return ostr;
}

std::string bintodec(const std::string &istr)
{
    int i = 0, sum = 0;
    for(auto iter = istr.crbegin(); iter != istr.crend(); ++iter) {
        if(*iter == '1')
            sum = sum + pow(2,i);
        ++i;
    }
    return std::to_string(sum);
}

std::string varwidthnot(const std::string &istr)
{
    std::vector<unsigned char> ovec(istr.size());
    std::transform(istr.begin(), istr.end(), ovec.begin(),
        [](unsigned char c){ return c == '0'?'1':'0'; });
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

std::string generate_gamma_rate(const std::vector<std::string> &tokens)
{
    std::string gamma_rate("");
    int zero_count;

    for(size_t i = 0; i < tokens[0].size(); ++i) {
        zero_count = 0;
        for(size_t j = 0; j < tokens.size(); ++j) {
            if(tokens[j][i] == '0') {
                ++zero_count;
            }
        }
        if(zero_count > (int)tokens.size()/2)
            gamma_rate = gamma_rate + '0';
        else
            gamma_rate = gamma_rate + '1';
    }
    return gamma_rate;
}

#endif