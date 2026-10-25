#include "TryCatch.h"

#include <iostream>
#include <stdexcept>

namespace
{
int checkedDivide(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument{"denominator must not be zero"};
    }
    return numerator / denominator;
}
}

void TryCatchExample::run()
{
    // Demonstrates reporting an exceptional condition by throwing and handling.
    // Exceptions separate error handling from the normal return-value path.
    try
    {
        const int quotient{checkedDivide(12, 0)};
        std::cout << "Quotient: " << quotient << '\n';
    }
    catch (const std::invalid_argument& error)
    {
        std::cout << "Cannot divide: " << error.what() << '\n';
    }

    // Catch by const reference to avoid copying; catch specific errors first.
    // RAII releases stack resources during unwinding. Expected: cannot divide message.
}