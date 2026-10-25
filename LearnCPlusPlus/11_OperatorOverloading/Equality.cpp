#include "Equality.h"

#include <iostream>

class Pixel
{
public:
    Pixel(int red, int green, int blue) : red_{red}, green_{green}, blue_{blue} {}
    bool operator==(const Pixel& other) const
    {
        return red_ == other.red_ && green_ == other.green_ && blue_ == other.blue_;
    }

private:
    int red_;
    int green_;
    int blue_;
};

void EqualityOperatorExample::run()
{
    // Demonstrates equality based on an object's meaningful value.
    // Overloading == lets callers compare domain values directly.
    const Pixel first{10, 20, 30};
    const Pixel same{10, 20, 30};
    const Pixel different{10, 20, 31};
    std::cout << "Equal pixel values: " << std::boolalpha << (first == same) << '\n';
    std::cout << "Different pixel values: " << (first == different) << '\n';

    // Compare every field that defines value identity. In C++20, a defaulted
    // operator== can reduce boilerplate. Expected output: true, then false.
}