#include "CapturesAndAlgorithms.h"
#include "LambdaBasics.h"

#include <iostream>

int main()
{
    std::cout << "=== C++ Lambdas ===\n";
    std::cout << "\n--- 1. Lambda syntax and call ---\n";
    LambdaBasicsExample basics;
    basics.run();
    std::cout << "\n--- 2. Capture and algorithm predicate ---\n";
    CapturesAndAlgorithmsExample captures;
    captures.run();
}