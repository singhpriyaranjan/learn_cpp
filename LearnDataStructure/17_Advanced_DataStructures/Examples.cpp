#include "Examples.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace
{
class FenwickTree
{
    std::vector<int> tree_;
public:
    explicit FenwickTree(std::size_t size) : tree_(size + 1, 0) {}
    void add(std::size_t index, int delta)
    {
        if (index >= tree_.size() - 1) throw std::out_of_range("Fenwick index");
        for (++index; index < tree_.size(); index += index & (~index + 1)) tree_[index] += delta;
    }
    int prefixSum(std::size_t count) const
    {
        if (count >= tree_.size()) throw std::out_of_range("Fenwick prefix");
        int total = 0; for (std::size_t index = count; index; index -= index & (~index + 1)) total += tree_[index]; return total;
    }
};
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: fenwick, all\n"; return 0; }
    if (choice != "all" && choice != "fenwick") { std::cerr << "Unknown example\n"; return 2; }
    FenwickTree sums(5); sums.add(0, 2); sums.add(2, 4); sums.add(4, 3);
    std::cout << "sum[0..2)=" << sums.prefixSum(3) << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    FenwickTree sums(4); sums.add(0, 2); sums.add(1, 3); sums.add(3, 5);
    return sums.prefixSum(0) == 0 && sums.prefixSum(2) == 5 && sums.prefixSum(4) == 10;
}