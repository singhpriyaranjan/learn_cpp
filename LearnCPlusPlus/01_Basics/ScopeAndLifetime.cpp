#include "ScopeAndLifetime.h"

#include <iostream>
#include <string>

void ScopeAndLifetimeExample::run()
{
    // Demonstrates block scope and automatic object lifetime. A local object
    // exists from its initialization until control leaves its enclosing block.
    // Braces create a nested scope; a name declared there is not visible outside.
    const std::string outerMessage{"The outer object is still alive."};
    std::cout << "Scope and lifetime: beginning the example.\n";

    {
        const std::string innerMessage{"The inner object lives in this block."};
        std::cout << innerMessage << '\n';
    } // innerMessage's lifetime ends here.

    std::cout << outerMessage << '\n';

    // The inner object is destroyed when its scope ends, before run() returns.
    // Common mistake: returning a reference or pointer to a local object that
    // has already gone out of scope. Good practice: make ownership and scope
    // visible, and keep objects in the narrowest scope that needs them.
    // Expected output:
    // Scope and lifetime: beginning the example.
    // The inner object lives in this block.
    // The outer object is still alive.
}