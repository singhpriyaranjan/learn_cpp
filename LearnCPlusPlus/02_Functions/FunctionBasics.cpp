#include "FunctionBasics.h"

#include <iostream>

int FunctionBasicsExample::add(int left, int right) const
{
    return left + right;
}

void FunctionBasicsExample::run()
{
    // Demonstrates a function with parameters and a return value. Functions
    // package a named operation so it can be reused and tested independently.
    // Syntax: return_type name(parameter_type parameter) { ... }
    const int firstNumber{12};
    const int secondNumber{5};
    const int sum{add(firstNumber, secondNumber)};
    std::cout << firstNumber << " + " << secondNumber << " = " << sum << '\n';

    // Arguments initialize the parameters; the returned int initializes sum.
    // Keep functions focused on one operation. Expected output: 12 + 5 = 17.
}