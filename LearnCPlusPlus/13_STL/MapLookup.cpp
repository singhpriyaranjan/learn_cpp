#include "MapLookup.h"

#include <iostream>
#include <map>
#include <string>

void MapLookupExample::run()
{
    // Demonstrates std::map for ordered key-to-value lookup.
    // A map keeps unique keys sorted and provides find() for safe lookup.
    std::map<std::string, int> inventory{{"pens", 12}, {"notebooks", 4}};
    inventory["pens"] += 3;

    const auto item{inventory.find("notebooks")};
    if (item != inventory.end())
    {
        std::cout << item->first << ": " << item->second << '\n';
    }

    // operator[] inserts a missing key with a default value; find() does not.
    // Choose the container by access needs (unordered_map is an alternative).
    // Expected output: notebooks: 4.
}