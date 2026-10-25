#include "Examples.h"
#include "Solutions.h"
#include <iostream>
#include <vector>

int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: pair-sum, all\n"; return 0; }
    if (choice != "all" && choice != "pair-sum") { std::cerr << "Unknown example\n"; return 2; }
    std::cout << "Has pair summing to 10: " << std::boolalpha << hasPairWithSum({2, 7, 11, 15}, 10) << '\n';
    return 0;
}
bool TopicExamples::checksPass() const
{
    return hasPairWithSum({2, 7, 11, 15}, 9) && !hasPairWithSum({1, 2, 3}, 20) &&
           !hasPairWithSum({4}, 8) && hasPairWithSum({2, 2}, 4);
}