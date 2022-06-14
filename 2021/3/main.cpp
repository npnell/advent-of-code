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
    unsigned int power_consumption = std::stoi(bintodec(gamma_rate)) * std::stoi(bintodec((epsilon_rate)));

    std::cout << "Part 1 answer: " << power_consumption << "\n";

    std::string o2_gen_rating = get_oxygen_generator_rating(tokens);
    std::string co2_scrub_rating = get_co2_scrubber_rating(tokens);
    unsigned int life_support_rating = std::stoi(bintodec(o2_gen_rating)) * std::stoi(bintodec((co2_scrub_rating)));

    std::cout << "Part 2 answer: " << life_support_rating << "\n";
    
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    initialize();
}