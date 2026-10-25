#include "AbstractInterfaces.h"

#include <iostream>

class Printable
{
public:
    virtual ~Printable() = default;
    virtual void print() const = 0;
};

class Receipt : public Printable
{
public:
    explicit Receipt(int totalCents) : totalCents_{totalCents} {}
    void print() const override
    {
        std::cout << "Receipt total: " << totalCents_ << " cents\n";
    }

private:
    int totalCents_;
};

void AbstractInterfacesExample::run()
{
    // Demonstrates a pure virtual function and abstract interface. The base
    // specifies required behavior; concrete classes provide implementations.
    // A class with = 0 cannot be instantiated directly.
    Receipt receipt{875};
    const Printable& printable{receipt};
    printable.print();

    // Keep interfaces small so each implementation has a clear contract.
    // Expected output: Receipt total: 875 cents.
}