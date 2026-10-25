#include "ProtectingSharedState.h"
#include "StartingAThread.h"

#include <iostream>

int main()
{
    std::cout << "=== C++ Concurrency ===\n";
    std::cout << "\n--- 1. Start and join a worker ---\n";
    StartingAThreadExample start;
    start.run();
    std::cout << "\n--- 2. Protect shared state with a mutex ---\n";
    ProtectingSharedStateExample sharedState;
    sharedState.run();
}