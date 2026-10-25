#pragma once

#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>

template <typename Iterator>
int sumRange(Iterator first, Iterator last)
{
    int total = 0;
    for (; first != last; ++first)
    {
        total += *first;
    }
    return total;
}

class FoundationsExamples
{
public:
    int run(int argc, char** argv) const;
    bool checksPass() const;

private:
    void demonstrateComplexity() const;
    void demonstrateRecursion() const;
    void demonstrateMemoryAndOwnership() const;
    void demonstrateIteratorsAndTemplates() const;
};

int factorial(int value);