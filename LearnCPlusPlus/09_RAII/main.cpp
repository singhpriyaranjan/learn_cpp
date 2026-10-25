#include "ExceptionSafeScope.h"
#include "ScopedResource.h"

#include <iostream>

int main()
{
    std::cout << "=== RAII ===\n";
    std::cout << "\n--- 1. Resource lifetime follows scope ---\n";
    ScopedResourceExample resource;
    resource.run();
    std::cout << "\n--- 2. Cleanup during exception unwinding ---\n";
    ExceptionSafeScopeExample exceptionSafety;
    exceptionSafety.run();
}