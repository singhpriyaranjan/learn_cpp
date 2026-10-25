#include "CustomException.h"

#include <iostream>
#include <stdexcept>
#include <string>

class InsufficientFunds : public std::runtime_error
{
public:
    explicit InsufficientFunds(int requested)
        : std::runtime_error{"withdrawal exceeds account balance"},
          requested_{requested}
    {
    }

    int requested() const { return requested_; }

private:
    int requested_;
};

void CustomExceptionExample::run()
{
    // Demonstrates a domain-specific exception carrying structured context.
    // Use a custom type when callers can respond differently to this failure.
    const int balance{30};
    const int requested{45};
    try
    {
        if (requested > balance)
        {
            throw InsufficientFunds{requested};
        }
    }
    catch (const InsufficientFunds& error)
    {
        std::cout << error.what() << "; requested " << error.requested() << '\n';
    }

    // Throw by value and catch by const reference. Do not use exceptions for
    // ordinary expected branching. Expected output includes requested 45.
}