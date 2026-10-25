#include "Examples.h"
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

namespace
{
struct Task { int priority; std::string name; };
struct LowerPriorityFirst { bool operator()(const Task& left, const Task& right) const { return left.priority < right.priority; } };
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: task-order, all\n"; return 0; }
    if (choice != "all" && choice != "task-order") { std::cerr << "Unknown example\n"; return 2; }
    std::priority_queue<Task, std::vector<Task>, LowerPriorityFirst> tasks;
    tasks.push({1, "background"}); tasks.push({5, "urgent"}); tasks.push({3, "normal"});
    std::cout << "Next task: " << tasks.top().name << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    std::priority_queue<int> values; values.push(2); values.push(9); values.push(4);
    return values.top() == 9;
}