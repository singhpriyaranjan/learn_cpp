#include "MoveStandardLibrary.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

void MoveStandardLibraryExample::run()
{
    // Demonstrates moving a standard-library container into a destination.
    // Move semantics can transfer owned storage and avoid copying many elements.
    std::vector<std::string> source{"red", "green", "blue"};
    const std::size_t sourceSizeBefore{source.size()};
    std::vector<std::string> destination{std::move(source)};
    std::cout << "Elements transferred: " << destination.size() << '\n';
    std::cout << "Source size before move: " << sourceSizeBefore << '\n';

    // A moved-from standard container is valid but its exact contents are not
    // generally guaranteed. Reassign before using it as if populated.
    // Expected output: 3 elements transferred; source previously held 3.
}