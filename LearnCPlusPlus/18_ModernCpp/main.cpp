#include "OptionalValues.h"
#include "StructuredBindings.h"

#include <iostream>

int main()
{
    std::cout << "=== Modern C++17 Features ===\n";
    std::cout << "\n--- 1. Optional values ---\n";
    OptionalValuesExample optional;
    optional.run();
    std::cout << "\n--- 2. Structured bindings ---\n";
    StructuredBindingsExample bindings;
    bindings.run();
}