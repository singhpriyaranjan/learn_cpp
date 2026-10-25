#include "LambdaBasics.h"

#include <iostream>

void LambdaBasicsExample::run()
{
    // Demonstrates a lambda, an unnamed function object useful near its call.
    // Syntax: [captures](parameters) { body }.
    const auto multiply{[](int left, int right) { return left * right; }};
    const int product{multiply(6, 7)};
    std::cout << "6 times 7 is " << product << '\n';

    // The compiler gives the lambda a unique callable type; auto stores it.
    // Keep a named function when behavior is broadly reused or needs a clear API.
    // Expected output: 6 times 7 is 42.
}