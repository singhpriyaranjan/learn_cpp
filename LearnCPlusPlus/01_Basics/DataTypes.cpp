#include "DataTypes.h"

#include <cstddef>
#include <iostream>
#include <string>

void DataTypesExample::run()
{
    // Demonstrates common fundamental and library types. Types tell the
    // compiler how values are represented and which operations are valid.
    // Basic syntax: type variable{value};
    int itemCount{3};
    double temperatureCelsius{21.5};
    bool isReady{true};
    char grade{'A'};
    std::string topic{"Data types"};

    std::cout << topic << ": count=" << itemCount
              << ", temperature=" << temperatureCelsius
              << ", ready=" << std::boolalpha << isReady
              << ", grade=" << grade << '\n';

    // sizeof reports bytes, not a universal fixed size for every platform.
    // Common mistake: assuming int or long has the same size everywhere.
    // Good practice: use a type whose meaning fits the value; use fixed-width
    // types from <cstdint> when a specific integer width is required.
    const std::size_t integerBytes{sizeof(itemCount)};
    std::cout << "int occupies " << integerBytes << " byte(s) here.\n";

    // Expected output (the int size line can vary by platform):
    // Data types: count=3, temperature=21.5, ready=true, grade=A
    // int occupies 4 byte(s) here.
}