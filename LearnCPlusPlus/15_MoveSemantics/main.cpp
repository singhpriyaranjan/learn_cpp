#include "MoveConstruction.h"
#include "MoveStandardLibrary.h"

#include <iostream>

int main()
{
    std::cout << "=== Move Semantics ===\n";
    std::cout << "\n--- 1. Move constructor ---\n";
    MoveConstructionExample construction;
    construction.run();
    std::cout << "\n--- 2. Moving a standard container ---\n";
    MoveStandardLibraryExample standardLibrary;
    standardLibrary.run();
}