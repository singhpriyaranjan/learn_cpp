#include "Examples.h"
#include <iostream>
#include <queue>
#include <vector>

namespace
{
class Graph
{
    std::vector<std::vector<int>> edges_;
public:
    explicit Graph(std::size_t count) : edges_(count) {}
    void addDirected(int from, int to) { edges_.at(static_cast<std::size_t>(from)).push_back(to); }
    std::vector<int> breadthFirst(int start) const
    {
        std::vector<int> order; std::vector<bool> seen(edges_.size(), false); std::queue<int> pending;
        seen.at(static_cast<std::size_t>(start)) = true; pending.push(start);
        while (!pending.empty()) { const int current = pending.front(); pending.pop(); order.push_back(current);
            for (int next : edges_.at(static_cast<std::size_t>(current))) if (!seen.at(static_cast<std::size_t>(next))) { seen[static_cast<std::size_t>(next)] = true; pending.push(next); } }
        return order;
    }
};
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: bfs, all\n"; return 0; }
    if (choice != "all" && choice != "bfs") { std::cerr << "Unknown example\n"; return 2; }
    Graph graph(4); graph.addDirected(0, 1); graph.addDirected(0, 2); graph.addDirected(1, 3); graph.addDirected(2, 3);
    std::cout << "BFS:"; for (int node : graph.breadthFirst(0)) std::cout << ' ' << node; std::cout << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    Graph graph(4); graph.addDirected(0, 1); graph.addDirected(0, 2); graph.addDirected(2, 3);
    return graph.breadthFirst(0) == std::vector<int>({0, 1, 2, 3}) && graph.breadthFirst(1) == std::vector<int>({1});
}