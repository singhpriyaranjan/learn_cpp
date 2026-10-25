#include "Examples.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace
{
class IntStack
{
    std::vector<int> values_;
public:
    void push(int value) { values_.push_back(value); }
    bool empty() const { return values_.empty(); }
    int pop()
    {
        if (empty()) throw std::underflow_error("pop on empty stack");
        int value = values_.back(); values_.pop_back(); return value;
    }
};
bool balanced(const std::string& text)
{
    IntStack stack;
    for (char ch : text)
    {
        if (ch == '(') stack.push(1);
        if (ch == ')') { if (stack.empty()) return false; stack.pop(); }
    }
    return stack.empty();
}
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: parentheses, all\n"; return 0; }
    if (choice != "all" && choice != "parentheses") { std::cerr << "Unknown example\n"; return 2; }
    std::cout << "((a+b)) balanced=" << std::boolalpha << balanced("((a+b))") << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    return balanced("") && balanced("()(() )") && !balanced(")(") && !balanced("(()");
}