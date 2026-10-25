#include "ConstructorInitialization.h"
#include "DestructorLifetime.h"

#include <iostream>

int main()
{
    std::cout << "=== Constructors and Destructors ===\n";
    std::cout << "\n--- 1. Constructor initialization ---\n";
    ConstructorInitializationExample initialization;
    initialization.run();
    std::cout << "\n--- 2. Destructor and scope lifetime ---\n";
    DestructorLifetimeExample lifetime;
    lifetime.run();
}