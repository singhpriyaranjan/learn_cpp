#include "AbstractInterfaces.h"
#include "VirtualDispatch.h"

#include <iostream>

int main()
{
    std::cout << "=== C++ Polymorphism ===\n";
    std::cout << "\n--- 1. Virtual dispatch and override ---\n";
    VirtualDispatchExample dispatch;
    dispatch.run();
    std::cout << "\n--- 2. Abstract interfaces ---\n";
    AbstractInterfacesExample interfaces;
    interfaces.run();
}