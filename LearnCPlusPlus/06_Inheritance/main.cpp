#include "ProtectedMembers.h"
#include "PublicInheritance.h"

#include <iostream>

int main()
{
    std::cout << "=== C++ Inheritance ===\n";
    std::cout << "\n--- 1. Public is-a inheritance ---\n";
    PublicInheritanceExample publicInheritance;
    publicInheritance.run();
    std::cout << "\n--- 2. Protected base interface ---\n";
    ProtectedMembersExample protectedMembers;
    protectedMembers.run();
}