#include "MapLookup.h"
#include "VectorAndAlgorithms.h"

#include <iostream>

int main()
{
    std::cout << "=== Standard Library Containers and Algorithms ===\n";
    std::cout << "\n--- 1. vector and sort ---\n";
    VectorAndAlgorithmsExample vectorExample;
    vectorExample.run();
    std::cout << "\n--- 2. map lookup ---\n";
    MapLookupExample mapExample;
    mapExample.run();
}