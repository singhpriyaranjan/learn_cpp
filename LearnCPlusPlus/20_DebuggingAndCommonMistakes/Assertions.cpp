#include "Assertions.h"

#include <cassert>
#include <iostream>

int calculateRectangleArea(int width, int height)
{
    assert(width >= 0);
    assert(height >= 0);
    return width * height;
}

void AssertionsExample::run()
{
    // Demonstrates assertions as executable documentation of programmer
    // assumptions. In Debug builds a failed assertion stops at the violated rule.
    const int width{5};
    const int height{3};
    const int area{calculateRectangleArea(width, height)};
    std::cout << "Rectangle area: " << area << '\n';

    // Assertions may be disabled by NDEBUG in Release builds, so never use
    // them to validate untrusted runtime input. Expected output: area 15.
}