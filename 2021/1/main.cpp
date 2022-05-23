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
    log<std::string>("Part 1 answer: ");
    log<decltype(depth_increments)>(depth_increments);

    auto grouped_depth_increments = sweep(grouped_depths(depths));
    log<std::string>("Part 2 answer: ");
    log<decltype(grouped_depth_increments)>(grouped_depth_increments);
    
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    initialize();
}