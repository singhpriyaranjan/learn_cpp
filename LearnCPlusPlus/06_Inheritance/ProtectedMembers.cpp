#include "ProtectedMembers.h"

#include <iostream>

class ShapeBase
{
protected:
    explicit ShapeBase(int sides) : sides_{sides} {}
    int sides() const { return sides_; }

private:
    int sides_;
};

class TriangleShape : public ShapeBase
{
public:
    TriangleShape() : ShapeBase{3} {}
    void describe() const { std::cout << "Triangle sides: " << sides() << '\n'; }
};

void ProtectedMembersExample::run()
{
    // Demonstrates protected access: derived types may use it, outside callers
    // may not. It supports a controlled interface shared with subclasses.
    TriangleShape triangle;
    triangle.describe();

    // Protected state can couple subclasses to base implementation. Prefer
    // private data with a narrow protected function when possible.
    // Expected output: Triangle sides: 3.
}