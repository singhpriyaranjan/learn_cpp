#include "Pointers.h"

#include <iostream>

void PointersExample::run()
{
    // Demonstrates a pointer, which stores an object's address. Pointers can
    // be reseated and represent absence with nullptr.
    // Syntax: type* p{&object}; read or write the pointed-to value with *p.
    int temperature{18};
    int* temperaturePointer{&temperature};
    std::cout << "Value: " << *temperaturePointer << '\n';
    *temperaturePointer = 20;
    std::cout << "Updated through pointer: " << temperature << '\n';

    int* optionalPointer{nullptr};
    if (optionalPointer == nullptr)
    {
        std::cout << "Optional pointer is empty.\n";
    }

    // Dereferencing nullptr or a dangling pointer is undefined behavior.
    // Check nullable pointers and prefer references when absence is impossible.
    // Expected output: Value 18, updated value 20, then the empty-pointer message.
}