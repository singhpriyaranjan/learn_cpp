#include "Examples.h"

#include <iostream>

int main()
{
    FoundationsExamples examples;
    if (!examples.checksPass())
    {
        std::cerr << "Foundations invariant checks failed\n";
        return 1;
    }
    std::cout << "Foundations invariant checks passed\n";
    return 0;
}