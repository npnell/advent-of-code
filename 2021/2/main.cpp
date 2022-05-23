// Advent of Code 2021
// Day 2: Dive!

#include "process.h"

int initialize(void) {
    int h_pos = 0;
    int depth = 0;
    std::vector<char> buffer;
    if(read_file(buffer, "input.txt")) {
        exit(EXIT_FAILURE);
    }

    auto tokens = tokenize_buffer(buffer); 
    auto commands = parse(tokens);

    traverse(commands, h_pos, depth);
    log<std::string>("Part 1 answer: ");
    log<decltype(h_pos)>(h_pos*depth);

    int nh_pos = 0;
    int ndepth = 0;
    int aim = 0;
    ntraverse(commands, nh_pos, ndepth, aim);
    log<std::string>("Part 2 answer: ");
    log<decltype(nh_pos)>(nh_pos*ndepth);
    
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    initialize();
}