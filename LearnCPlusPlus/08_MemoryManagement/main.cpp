#include "RawAllocation.h"
#include "StackAndHeap.h"

#include <iostream>

int main()
{
    std::cout << "=== C++ Memory Management ===\n";
    std::cout << "\n--- 1. Automatic and dynamic object lifetime ---\n";
    StackAndHeapExample storage;
    storage.run();
    std::cout << "\n--- 2. Raw new and delete (learning only) ---\n";
    RawAllocationExample rawAllocation;
    rawAllocation.run();
}