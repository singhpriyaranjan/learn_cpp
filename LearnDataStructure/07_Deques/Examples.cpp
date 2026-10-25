#include "Examples.h"
#include <array>
#include <iostream>
#include <stdexcept>

namespace
{
class RingDeque
{
    static constexpr std::size_t capacity_ = 5;
    std::array<int, capacity_> items_{};
    std::size_t front_ = 0, size_ = 0;
public:
    bool pushFront(int value) { if (size_ == capacity_) return false; front_ = (front_ + capacity_ - 1) % capacity_; items_[front_] = value; ++size_; return true; }
    bool pushBack(int value) { if (size_ == capacity_) return false; items_[(front_ + size_) % capacity_] = value; ++size_; return true; }
    int popFront() { if (!size_) throw std::underflow_error("empty deque"); int value = items_[front_]; front_ = (front_ + 1) % capacity_; --size_; return value; }
    int popBack() { if (!size_) throw std::underflow_error("empty deque"); const auto index = (front_ + size_ - 1) % capacity_; int value = items_[index]; --size_; return value; }
};
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: ring, all\n"; return 0; }
    if (choice != "all" && choice != "ring") { std::cerr << "Unknown example\n"; return 2; }
    RingDeque deque; deque.pushFront(2); deque.pushFront(1); deque.pushBack(3);
    std::cout << "Both ends: " << deque.popFront() << ' ' << deque.popBack() << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    RingDeque deque;
    return deque.pushBack(2) && deque.pushFront(1) && deque.pushBack(3) &&
           deque.popFront() == 1 && deque.popBack() == 3 && deque.popFront() == 2;
}