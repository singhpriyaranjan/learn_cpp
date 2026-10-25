#include "ClassTemplate.h"
#include "FunctionTemplate.h"

#include <iostream>

int main()
{
    std::cout << "=== C++ Templates ===\n";
    std::cout << "\n--- 1. Function template ---\n";
    FunctionTemplateExample functionTemplate;
    functionTemplate.run();
    std::cout << "\n--- 2. Class template ---\n";
    ClassTemplateExample classTemplate;
    classTemplate.run();
}