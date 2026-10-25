#include "Examples.h"

#include <memory>
#include <stdexcept>
#include <vector>

int factorial(int value)
{
    if (value < 0)
    {
        throw std::invalid_argument("factorial requires a non-negative value");
    }
    if (value < 2)
    {
        return 1;
    }
    return value * factorial(value - 1);
}

void FoundationsExamples::demonstrateComplexity() const
{
    const std::vector<int> values{2, 4, 6, 8};
    int total = 0;
    for (const int value : values)
    {
        total += value;
    }
    std::cout << "One pass over " << values.size() << " items: O(n), sum=" << total << '\n';
}

void FoundationsExamples::demonstrateRecursion() const
{
    std::cout << "factorial(5)=" << factorial(5)
              << " (five calls; O(n) time and O(n) call-stack space)\n";
}

void FoundationsExamples::demonstrateMemoryAndOwnership() const
{
    int stackValue = 17;
    int* observer = &stackValue;
    auto ownedValue = std::make_unique<int>(23);
    std::cout << "stack object=" << stackValue << ", observer dereference=" << *observer
              << ", uniquely owned heap object=" << *ownedValue << '\n';
}

void FoundationsExamples::demonstrateIteratorsAndTemplates() const
{
    const std::vector<int> values{3, 1, 4};
    std::cout << "Generic iterator sum=" << sumRange(values.begin(), values.end()) << '\n';
}

int FoundationsExamples::run(int argc, char** argv) const
{
    if (argc > 1 && std::string(argv[1]) == "--help")
    {
        std::cout << "Examples: complexity, recursion, memory, iterators (or omit for all)\n";
        return 0;
    }

    const std::string selected = argc > 1 ? argv[1] : "all";
    std::cout << "=== 01 Foundations ===\n";
    if (selected == "all" || selected == "complexity") demonstrateComplexity();
    if (selected == "all" || selected == "recursion") demonstrateRecursion();
    if (selected == "all" || selected == "memory") demonstrateMemoryAndOwnership();
    if (selected == "all" || selected == "iterators") demonstrateIteratorsAndTemplates();
    if (selected != "all" && selected != "complexity" && selected != "recursion" &&
        selected != "memory" && selected != "iterators")
    {
        std::cerr << "Unknown example: " << selected << " (use --help)\n";
        return 2;
    }
    return 0;
}

bool FoundationsExamples::checksPass() const
{
    const std::vector<int> values{3, 1, 4};
    return factorial(0) == 1 && factorial(5) == 120 &&
           sumRange(values.begin(), values.end()) == 8;
}