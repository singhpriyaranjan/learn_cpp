#include "FactoryPattern.h"
#include "StrategyPattern.h"

#include <iostream>

int main()
{
    std::cout << "=== Design Patterns ===\n";
    std::cout << "\n--- 1. Strategy: select behavior ---\n";
    StrategyPatternExample strategy;
    strategy.run();
    std::cout << "\n--- 2. Factory function: select a type ---\n";
    FactoryPatternExample factory;
    factory.run();
}