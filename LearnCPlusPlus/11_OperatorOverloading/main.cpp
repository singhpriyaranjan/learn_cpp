#include "Equality.h"
#include "VectorAddition.h"

#include <iostream>

int main()
{
    std::cout << "=== Operator Overloading ===\n";
    std::cout << "\n--- 1. Arithmetic value operation ---\n";
    VectorAdditionExample addition;
    addition.run();
    std::cout << "\n--- 2. Value equality ---\n";
    EqualityOperatorExample equality;
    equality.run();
}