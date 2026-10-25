#include "FunctionTemplate.h"

#include <iostream>
#include <string>

template <typename T>
T largerOf(T first, T second)
{
    return first < second ? second : first;
}

void FunctionTemplateExample::run()
{
    // Demonstrates a function template: one function pattern works for types
    // that support the required comparison operation.
    // Syntax: template <typename T> T function(T value).
    const int largerNumber{largerOf(7, 12)};
    const std::string largerWord{largerOf(std::string{"pear"}, std::string{"plum"})};
    std::cout << "Larger number: " << largerNumber << '\n';
    std::cout << "Later word alphabetically: " << largerWord << '\n';

    // The compiler instantiates a version for each used type. Both arguments
    // must deduce a compatible T, and that type must support operator<.
    // Expected output: 12 and plum.
}