#include "FunctionOverloading.h"

#include <iostream>

int FunctionOverloadingExample::area(int side) const
{
    return side * side;
}

int FunctionOverloadingExample::area(int width, int height) const
{
    return width * height;
}

void FunctionOverloadingExample::run()
{
    // Demonstrates overloads: related operations share a name but have
    // different parameter lists. The compiler chooses from argument types/count.
    // Syntax: same_name(type) and same_name(type, type).
    const int squareArea{area(4)};
    const int rectangleArea{area(4, 6)};
    std::cout << "Square area: " << squareArea << '\n';
    std::cout << "Rectangle area: " << rectangleArea << '\n';

    // Return type alone cannot distinguish overloads. Avoid ambiguous conversions.
    // Expected output: Square area: 16; Rectangle area: 24.
}