#include "FunctionBasics.h"
#include "FunctionOverloading.h"

#include <iostream>

int main()
{
    std::cout << "=== C++ Functions ===\n";
    std::cout << "\n--- 1. Parameters and return values ---\n";
    FunctionBasicsExample basics;
    basics.run();
    std::cout << "\n--- 2. Function overloading ---\n";
    FunctionOverloadingExample overloading;
    overloading.run();
}