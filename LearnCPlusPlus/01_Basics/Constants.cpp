#include "Constants.h"

#include <iostream>

void ConstantsExample::run()
{
    // Demonstrates values that must not be changed after initialization.
    // const protects a value at runtime; constexpr requests compile-time
    // evaluation when its initializer is a constant expression.
    // Basic syntax: const type name{value}; constexpr type name{value};
    const double pricePerItem{2.50};
    constexpr int itemsPerBox{4};

    const double totalPrice{pricePerItem * itemsPerBox};
    std::cout << "One box contains " << itemsPerBox << " items and costs $"
              << totalPrice << ".\n";

    // A const value cannot be assigned a new value. A constexpr value can be
    // used where a compile-time constant is required. Not every const value
    // is known until runtime, so const and constexpr are not interchangeable.
    // Common mistake: leaving values mutable when they should never change.
    // Good practice: make values const by default; use constexpr when the
    // value is suitable and genuinely needed at compile time.
    // Expected output: One box contains 4 items and costs $10.
}