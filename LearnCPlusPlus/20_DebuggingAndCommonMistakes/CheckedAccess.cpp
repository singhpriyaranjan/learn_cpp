#include "CheckedAccess.h"

#include <iostream>
#include <stdexcept>
#include <vector>

void CheckedAccessExample::run()
{
    // Demonstrates checked container access and an explicit bounds failure.
    // vector::at validates an index and throws instead of reading invalid memory.
    const std::vector<int> readings{11, 14, 19};
    try
    {
        std::cout << "Reading 1: " << readings.at(1) << '\n';
        std::cout << "Reading 4: " << readings.at(4) << '\n';
    }
    catch (const std::out_of_range& error)
    {
        std::cout << "Caught invalid index: " << error.what() << '\n';
    }

    // operator[] is unchecked; use at() when indices may be invalid. A
    // debugger breakpoint in the catch block exposes the invalid access path.
    // Expected: reading 1 is 14, followed by the out-of-range message.
}