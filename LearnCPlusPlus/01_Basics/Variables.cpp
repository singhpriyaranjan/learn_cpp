#include "Variables.h"

#include <iostream>
#include <string>

void VariablesExample::run()
{
    // Demonstrates named storage and initialization. Variables let a program
    // keep values and refer to them by meaningful names.
    // Basic syntax: type name{initial_value};
    // Braces initialize directly and avoid many accidental narrowing cases.
    int lessonNumber{1};
    double completion{0.25};
    std::string lessonName{"Variables and initialization"};

    // Separate values make it easy to inspect each variable in a debugger.
    std::cout << "Lesson " << lessonNumber << ": " << lessonName << '\n';
    std::cout << "Completion: " << completion * 100.0 << "%\n";

    // Common mistake: reading an uninitialized built-in local variable.
    // Good practice: initialize variables when they are declared.
    // Expected output:
    // Lesson 1: Variables and initialization
    // Completion: 25%
}