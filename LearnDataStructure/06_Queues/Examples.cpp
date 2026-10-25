#include "Examples.h"
#include <array>
#include <iostream>
#include <stdexcept>

namespace
{
class CircularQueue
{
    static constexpr std::size_t capacity_ = 4;
    std::array<int, capacity_> data_{};
    std::size_t head_ = 0;
    std::size_t size_ = 0;
public:
    bool enqueue(int value)
    {
        if (size_ == capacity_) return false;
        const std::size_t tail = (head_ + size_) % capacity_;
        data_[tail] = value; ++size_; return true;
    }
    int dequeue()
    {
        if (size_ == 0) throw std::underflow_error("dequeue on empty queue");
        int value = data_[head_]; head_ = (head_ + 1) % capacity_; --size_; return value;
    }
    std::size_t size() const { return size_; }
};
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: circular, all\n"; return 0; }
    if (choice != "all" && choice != "circular") { std::cerr << "Unknown example\n"; return 2; }
    CircularQueue queue; queue.enqueue(10); queue.enqueue(20);
    std::cout << "FIFO dequeue=" << queue.dequeue() << ", remaining=" << queue.size() << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    CircularQueue queue;
    if (!queue.enqueue(1) || !queue.enqueue(2) || !queue.enqueue(3) || !queue.enqueue(4)) return false;
    if (queue.enqueue(5) || queue.dequeue() != 1 || !queue.enqueue(5)) return false;
    return queue.dequeue() == 2 && queue.dequeue() == 3 && queue.dequeue() == 4 &&
           queue.dequeue() == 5 && queue.size() == 0;
}