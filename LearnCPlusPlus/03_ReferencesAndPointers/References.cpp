#include "References.h"

#include <iostream>

void ReferencesExample::addBonus(int& score) const
{
    score += 10;
}

void ReferencesExample::run()
{
    // Demonstrates an lvalue reference, an alias for an existing object.
    // References let a function modify a caller's value without copying it.
    // Syntax: type& alias{existing_object};
    int score{40};
    int& scoreAlias{score};
    scoreAlias += 5;
    addBonus(score);
    std::cout << "Score after updates through aliases: " << score << '\n';

    // A reference must be initialized and cannot be reseated. Both updates
    // affect one int. Do not return a reference to a local variable.
    // Expected output: Score after updates through aliases: 55.
}