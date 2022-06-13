// Advent of Code 2021
// Day 1: Sonar Sweep

#include "process.h"

int initialize(void)
{
    std::vector<char> buffer;
    if(read_file(buffer, "input.txt")) {
        exit(EXIT_FAILURE);
    }
    auto depths = tokenize_buffer(buffer);

    auto depth_increments = sweep(depths);
    std::cout << "Part 1 answer: " << depth_increments << "\n";

    auto grouped_depth_increments = sweep(grouped_depths(depths));
    std::cout << "Part 2 answer: " << grouped_depth_increments << "\n";
    
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    initialize();
}