#include "Examples.h"
#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: selection, all\n"; return 0; }
    if (choice != "all" && choice != "selection") { std::cerr << "Unknown example\n"; return 2; }
    std::array<int, 3> fixed{1, 2, 3}; std::vector<int> dynamic{1, 2}; std::deque<int> ends{1, 2};
    std::list<int> linked{1, 2}; std::forward_list<int> forward{1, 2};
    std::stack<int> lifo; std::queue<int> fifo; std::priority_queue<int> priority;
    std::set<int> ordered{3, 1, 2}; std::map<int, int> mapping{{1, 10}};
    std::unordered_set<int> hashed{1, 2}; std::unordered_map<int, int> lookup{{1, 10}};
    lifo.push(1); fifo.push(1); priority.push(1);
    std::cout << "array=" << fixed.size() << " vector=" << dynamic.size() << " deque=" << ends.size()
              << " list=" << linked.size() << " forward_list front=" << forward.front()
              << " set minimum=" << *ordered.begin() << " map value=" << mapping.at(1)
              << " hash hit=" << hashed.count(1) + lookup.count(1) << '\n';
    return 0;
}
bool TopicExamples::checksPass() const
{
    std::vector<int> values{2, 1}; std::set<int> ordered(values.begin(), values.end());
    std::unordered_map<int, int> map{{4, 9}};
    return values.size() == 2 && *ordered.begin() == 1 && map.at(4) == 9;
}