#include "Solutions.h"
#include <limits>
#include <unordered_set>

bool hasPairWithSum(const std::vector<int>& values, int target)
{
    std::unordered_set<int> seen;
    for (int value : values)
    {
        const long long needed = static_cast<long long>(target) - value;
        if (needed >= static_cast<long long>(std::numeric_limits<int>::min()) &&
            needed <= static_cast<long long>(std::numeric_limits<int>::max()) &&
            seen.count(static_cast<int>(needed)) != 0) return true;
        seen.insert(value);
    }
    return false;
}