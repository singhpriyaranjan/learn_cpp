#include "Examples.h"
#include <array>
#include <iostream>
#include <optional>
#include <utility>
#include <vector>

namespace
{
class ChainedTable
{
    using Entry = std::pair<int, int>;
    std::array<std::vector<Entry>, 5> buckets_;
    std::size_t bucketFor(int key) const
    {
        const int remainder = key % static_cast<int>(buckets_.size());
        return static_cast<std::size_t>(remainder < 0 ? -remainder : remainder);
    }
public:
    void put(int key, int value)
    {
        auto& bucket = buckets_[bucketFor(key)];
        for (auto& entry : bucket) if (entry.first == key) { entry.second = value; return; }
        bucket.emplace_back(key, value);
    }
    std::optional<int> get(int key) const
    {
        for (const auto& entry : buckets_[bucketFor(key)]) if (entry.first == key) return entry.second;
        return std::nullopt;
    }
};
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: chaining, all\n"; return 0; }
    if (choice != "all" && choice != "chaining") { std::cerr << "Unknown example\n"; return 2; }
    ChainedTable table; table.put(1, 10); table.put(6, 60); table.put(1, 11);
    std::cout << "Collision bucket values: " << *table.get(1) << ", " << *table.get(6) << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    ChainedTable table; table.put(1, 7); table.put(6, 9); table.put(1, 8);
    return table.get(1) == 8 && table.get(6) == 9 && !table.get(2).has_value();
}