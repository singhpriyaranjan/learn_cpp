#include "StructuredBindings.h"

#include <iostream>
#include <map>
#include <string>
#include <tuple>

void StructuredBindingsExample::run()
{
    // Demonstrates C++17 structured bindings, which name tuple-like elements.
    // They make multi-value results and map entries easier to read.
    const auto [city, population] = std::tuple<std::string, int>{"Oslo", 709000};
    std::cout << city << " population: " << population << '\n';

    const std::map<std::string, int> scores{{"Ada", 98}, {"Linus", 91}};
    for (const auto& [name, score] : scores)
    {
        std::cout << name << ": " << score << '\n';
    }

    // `const auto&` avoids copying map entries. Use value bindings when a local
    // copy is intended. Expected lines show Oslo, Ada, and Linus with scores.
}