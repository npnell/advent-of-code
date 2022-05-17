// Advent of Code 2021
// Day 1: Sonar Sweep

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

int initialize(void) {
    std::vector<char> buffer;
    if(read_file(buffer, "input.txt")) {
        exit(EXIT_FAILURE);
    }
    auto depths = tokenize_buffer(buffer);

    auto grouped_depth_increments = sweep(grouped_depths(depths));
    log<decltype(grouped_depth_increments)>(grouped_depth_increments);

    // Part 1 of this problem requires couting single depth increments, which isn't very useful due to excessive noise in the data.
    // To get the solution for part 1, use sweep(depths) as below
    // auto depth_increments = sweep(depths);
    
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    initialize();
}