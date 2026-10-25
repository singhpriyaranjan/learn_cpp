#include "Examples.h"
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <utility>
#include <vector>

namespace
{
class DisjointSet
{
    std::vector<int> parent_, size_;
public:
    explicit DisjointSet(std::size_t count) : parent_(count), size_(count, 1) { std::iota(parent_.begin(), parent_.end(), 0); }
    int find(int item)
    {
        if (item < 0 || static_cast<std::size_t>(item) >= parent_.size()) throw std::out_of_range("set item");
        if (parent_[static_cast<std::size_t>(item)] != item) parent_[static_cast<std::size_t>(item)] = find(parent_[static_cast<std::size_t>(item)]);
        return parent_[static_cast<std::size_t>(item)];
    }
    bool unite(int left, int right)
    {
        int rootLeft = find(left), rootRight = find(right); if (rootLeft == rootRight) return false;
        if (size_[static_cast<std::size_t>(rootLeft)] < size_[static_cast<std::size_t>(rootRight)]) std::swap(rootLeft, rootRight);
        parent_[static_cast<std::size_t>(rootRight)] = rootLeft; size_[static_cast<std::size_t>(rootLeft)] += size_[static_cast<std::size_t>(rootRight)]; return true;
    }
};
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: connectivity, all\n"; return 0; }
    if (choice != "all" && choice != "connectivity") { std::cerr << "Unknown example\n"; return 2; }
    DisjointSet sets(5); sets.unite(0, 1); sets.unite(1, 2);
    std::cout << "0 connected to 2: " << std::boolalpha << (sets.find(0) == sets.find(2)) << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    DisjointSet sets(4); return sets.unite(0, 1) && sets.unite(1, 2) && !sets.unite(0, 2) && sets.find(0) == sets.find(2) && sets.find(3) != sets.find(2);
}