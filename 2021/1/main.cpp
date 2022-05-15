// Advent of Code 2021
// Day 1: Sonar Sweep

#include <typeinfo>
#include "read.h"

template<typename T>
void log(const T &output)
{
    std::cout << output << std::endl;
}

unsigned long sweep(const std::vector<int> &depths)
{
    unsigned long depth_increments = 0;
    if(begin(depths) != end(depths)) {
        for(auto iter = begin(depths); iter != end(depths) - 1; ++iter) {
            if(*iter < *(iter + 1)) {
                depth_increments = depth_increments + 1;
            }
        }   
    }
    return depth_increments;
}

int initialize(void) {
    std::vector<char> buffer;
    if(read_file(buffer, "input.txt")) {
        exit(EXIT_FAILURE);
    }
    auto depths = tokenize_buffer(buffer);
    auto depth_increments = sweep(depths);
    
    log<decltype(depth_increments)>(depth_increments);

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    initialize();
}