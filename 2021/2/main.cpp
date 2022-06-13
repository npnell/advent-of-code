// Advent of Code 2021
// Day 2: Dive!

#include "process.h"

int initialize(void) {
    std::vector<char> buffer;
    if(read_file(buffer, "input.txt")) {
        exit(EXIT_FAILURE);
    }

    auto tokens = tokenize_buffer(buffer); 
    auto commands = generate_commands(tokens);

    int h_pos = 0;
    int depth = 0;
    traverse(commands, h_pos, depth);
    std::cout << "Part 1 answer: " << h_pos*depth << "\n";

    int nh_pos = 0;
    int ndepth = 0;
    int aim = 0;
    traverse(commands, nh_pos, ndepth, aim);
    std::cout << "Part 2 answer: " << nh_pos*ndepth << "\n";
    
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    initialize();
}