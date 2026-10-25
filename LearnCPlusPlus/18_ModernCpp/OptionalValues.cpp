#include "OptionalValues.h"

#include <iostream>
#include <optional>

std::optional<int> findFirstEven(int first, int second)
{
    if (first % 2 == 0)
    {
        return first;
    }
    if (second % 2 == 0)
    {
        return second;
    }
    return std::nullopt;
}

void OptionalValuesExample::run()
{
    // Demonstrates std::optional for a result that may be absent.
    // It represents absence in the type instead of inventing a magic value.
    const std::optional<int> result{findFirstEven(7, 12)};
    if (result.has_value())
    {
        std::cout << "Found even value: " << result.value() << '\n';
    }
    else
    {
        std::cout << "No even value found.\n";
    }

    // Check before value(); value() on empty optional throws bad_optional_access.
    // Expected output: Found even value: 12.
}