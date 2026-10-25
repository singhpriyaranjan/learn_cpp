#include "TypeConversion.h"

#include <iostream>

void TypeConversionExample::run()
{
    // Demonstrates implicit and explicit conversions. Conversions allow
    // compatible values to be used with a different type.
    // Basic syntax: destination{source}; or static_cast<Type>(source).
    const int wholeNumber{7};
    const double implicitDecimal{wholeNumber};
    const double preciseValue{7.9};
    const int explicitWholeNumber{static_cast<int>(preciseValue)};

    std::cout << "Implicit int-to-double conversion: " << implicitDecimal
              << '\n';
    std::cout << "Explicit double-to-int conversion: " << explicitWholeNumber
              << '\n';

    // Converting a floating-point value to int discards the fractional part;
    // it does not round. Braced initialization rejects narrowing conversions.
    // Common mistake: relying on an implicit conversion that loses information.
    // Good practice: use static_cast to make intentional conversions visible.
    // Expected output:
    // Implicit int-to-double conversion: 7
    // Explicit double-to-int conversion: 7
}