#include "Operators.h"

#include <iostream>

void OperatorsExample::run()
{
    // Demonstrates arithmetic and comparison operators. Operators let
    // expressions calculate new values and compare existing values.
    // Basic syntax: result = left operator right;
    const int totalMinutes{137};
    const int minutesPerHour{60};
    const int hours{totalMinutes / minutesPerHour};
    const int remainingMinutes{totalMinutes % minutesPerHour};

    const bool isLongerThanOneHour{totalMinutes > minutesPerHour};
    std::cout << totalMinutes << " minutes is " << hours << " hour(s) and "
              << remainingMinutes << " minute(s).\n";
    std::cout << "Longer than one hour: " << std::boolalpha
              << isLongerThanOneHour << '\n';

    // Integer division discards the fractional part; % gives the remainder.
    // Common mistake: expecting 137 / 60 to produce a decimal when both
    // operands are integers. Good practice: choose operand types intentionally.
    // Expected output:
    // 137 minutes is 2 hour(s) and 17 minute(s).
    // Longer than one hour: true
}