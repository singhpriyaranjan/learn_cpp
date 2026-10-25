#include "Examples.h"

#include <iostream>

int main()
{
    TopicExamples examples;
    if (!examples.checksPass())
    {
        std::cerr << "Topic invariant checks failed\n";
        return 1;
    }
    std::cout << "Topic invariant checks passed\n";
    return 0;
}