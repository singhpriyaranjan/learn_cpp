#include "Examples.h"
#include <iostream>
#include <memory>
#include <vector>

namespace
{
class SinglyList
{
    struct Node { int value; std::unique_ptr<Node> next; };
    std::unique_ptr<Node> head_;
public:
    void pushFront(int value) { auto node = std::make_unique<Node>(Node{value, std::move(head_)}); head_ = std::move(node); }
    void reverse()
    {
        std::unique_ptr<Node> previous;
        while (head_)
        {
            auto next = std::move(head_->next);
            head_->next = std::move(previous);
            previous = std::move(head_);
            head_ = std::move(next);
        }
        head_ = std::move(previous);
    }
    std::vector<int> values() const
    {
        std::vector<int> result;
        for (const Node* current = head_.get(); current; current = current->next.get()) result.push_back(current->value);
        return result;
    }
};
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: singly, all\n"; return 0; }
    if (choice != "all" && choice != "singly") { std::cerr << "Unknown example\n"; return 2; }
    SinglyList list; list.pushFront(30); list.pushFront(20); list.pushFront(10); list.reverse();
    std::cout << "Reversed singly list: "; for (int value : list.values()) std::cout << value << ' '; std::cout << '\n';
    return 0;
}
bool TopicExamples::checksPass() const
{
    SinglyList list; list.reverse(); list.pushFront(2); list.pushFront(1); list.reverse();
    return list.values() == std::vector<int>({2, 1});
}