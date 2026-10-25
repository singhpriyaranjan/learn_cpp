#include "Assertions.h"
#include "CheckedAccess.h"

#include <iostream>

int main()
{
    std::cout << "=== Debugging and Common Mistakes ===\n";
    std::cout << "\n--- 1. Assert program invariants ---\n";
    AssertionsExample assertions;
    assertions.run();
    std::cout << "\n--- 2. Diagnose invalid container access ---\n";
    CheckedAccessExample access;
    access.run();
}