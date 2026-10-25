#include "StrategyPattern.h"

#include <iostream>

class ShippingStrategy
{
public:
    virtual ~ShippingStrategy() = default;
    virtual int costInCents(int distanceKm) const = 0;
};

class StandardShipping : public ShippingStrategy
{
public:
    int costInCents(int distanceKm) const override { return distanceKm * 5; }
};

class ExpressShipping : public ShippingStrategy
{
public:
    int costInCents(int distanceKm) const override { return 300 + distanceKm * 8; }
};

void StrategyPatternExample::run()
{
    // Demonstrates Strategy: interchangeable behavior behind one interface.
    // Composition lets a caller choose an algorithm at runtime.
    StandardShipping standard;
    ExpressShipping express;
    const ShippingStrategy& chosenStrategy{express};
    std::cout << "Express shipping cost: "
              << chosenStrategy.costInCents(10) << " cents\n";

    // Avoid a growing chain of mode conditionals when behaviors vary
    // independently. Two concrete strategies keep the example inspectable.
    // Expected output: Express shipping cost: 380 cents.
}