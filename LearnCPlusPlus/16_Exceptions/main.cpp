#include "CustomException.h"
#include "TryCatch.h"

#include <iostream>

int main()
{
    std::cout << "=== C++ Exceptions ===\n";
    std::cout << "\n--- 1. Throw and catch standard exception ---\n";
    TryCatchExample tryCatch;
    tryCatch.run();
    std::cout << "\n--- 2. Domain-specific exception ---\n";
    CustomExceptionExample custom;
    custom.run();
}