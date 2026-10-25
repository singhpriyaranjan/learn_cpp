#include "RawAllocation.h"

#include <iostream>

void RawAllocationExample::run()
{
    // Demonstrates raw dynamic allocation. It exists for low-level control and
    // understanding, but ownership is easy to get wrong.
    // Syntax: T* p = new T{value}; then delete p exactly once.
    int* scorePointer{new int{91}};
    std::cout << "Dynamically allocated score: " << *scorePointer << '\n';
    delete scorePointer;
    scorePointer = nullptr;

    // Missing delete leaks; double delete or using the stale address is invalid.
    // Prefer std::vector or smart pointers in ordinary C++17 code.
    // Expected output: Dynamically allocated score: 91.
}