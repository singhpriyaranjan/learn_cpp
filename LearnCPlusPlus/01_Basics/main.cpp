#include "Constants.h"
#include "DataTypes.h"
#include "Operators.h"
#include "ScopeAndLifetime.h"
#include "TypeConversion.h"
#include "Variables.h"

#include <iostream>

int main()
{
    std::cout << "=== C++ Basics ===\n";

    std::cout << "\n--- 1. Variables and initialization ---\n";
    VariablesExample variables;
    variables.run();

    std::cout << "\n--- 2. Fundamental data types ---\n";
    DataTypesExample dataTypes;
    dataTypes.run();

    std::cout << "\n--- 3. Constants ---\n";
    ConstantsExample constants;
    constants.run();

    std::cout << "\n--- 4. Operators ---\n";
    OperatorsExample operators;
    operators.run();

    std::cout << "\n--- 5. Scope and lifetime ---\n";
    ScopeAndLifetimeExample scopeAndLifetime;
    scopeAndLifetime.run();

    std::cout << "\n--- 6. Type conversion ---\n";
    TypeConversionExample typeConversion;
    typeConversion.run();

    return 0;
}