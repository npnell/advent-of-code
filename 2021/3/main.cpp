// Advent of Code 2021
// Day 3: Binary Diagnostic

#include "process.h"

int initialize(void) {
    std::vector<char> buffer;
    if(read_file(buffer, "input.txt")) {
        exit(EXIT_FAILURE);
    }

    auto tokens = tokenize_buffer(buffer);
    std::string gamma_rate = generate_gamma_rate(tokens);
    std::string epsilon_rate = varwidthnot(gamma_rate);
    unsigned int gamma_rate_dec = std::stoi(bintodec(gamma_rate));
    unsigned int epsilon_rate_dec = std::stoi(bintodec((epsilon_rate)));

    unsigned int power_consumption = gamma_rate_dec * epsilon_rate_dec;

    std::cout << "Part 1 answer: " << power_consumption << "\n";
    
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    initialize();
}