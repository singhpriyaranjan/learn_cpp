#include "VectorAddition.h"

#include <iostream>

class Vector2D
{
public:
    Vector2D(int x, int y) : x_{x}, y_{y} {}
    Vector2D operator+(const Vector2D& other) const
    {
        return Vector2D{x_ + other.x_, y_ + other.y_};
    }
    int x() const { return x_; }
    int y() const { return y_; }

private:
    int x_;
    int y_;
};

void VectorAdditionExample::run()
{
    // Demonstrates operator+ as readable syntax for a natural value operation.
    // A member overload receives the left operand as *this and right as a parameter.
    // Syntax: Result operator+(const Other& right) const.
    const Vector2D start{2, 3};
    const Vector2D movement{4, -1};
    const Vector2D destination{start + movement};
    std::cout << "Destination: (" << destination.x() << ", "
              << destination.y() << ")\n";

    // The operator returns a new value and does not mutate either operand.
    // Do not overload operators with surprising meanings. Expected: (6, 2).
}