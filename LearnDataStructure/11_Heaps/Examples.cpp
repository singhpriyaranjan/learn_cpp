#include "Examples.h"
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

namespace
{
class MinHeap
{
    std::vector<int> data_;
    void siftDown(std::size_t parent)
    {
        while (true) { std::size_t child = parent * 2 + 1; if (child >= data_.size()) return;
            if (child + 1 < data_.size() && data_[child + 1] < data_[child]) ++child;
            if (data_[parent] <= data_[child]) return; std::swap(data_[parent], data_[child]); parent = child; }
    }
public:
    void push(int value) { data_.push_back(value); std::size_t child = data_.size() - 1; while (child && data_[(child - 1) / 2] > data_[child]) { std::swap(data_[child], data_[(child - 1) / 2]); child = (child - 1) / 2; } }
    int pop() { if (data_.empty()) throw std::underflow_error("empty heap"); int result = data_.front(); data_.front() = data_.back(); data_.pop_back(); if (!data_.empty()) siftDown(0); return result; }
    std::size_t size() const { return data_.size(); }
};
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: min-heap, all\n"; return 0; }
    if (choice != "all" && choice != "min-heap") { std::cerr << "Unknown example\n"; return 2; }
    MinHeap heap; for (int value : {7, 2, 9, 1}) heap.push(value); std::cout << "Heap order:";
    while (heap.size()) std::cout << ' ' << heap.pop(); std::cout << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    MinHeap heap; for (int value : {5, 1, 4, 2}) heap.push(value);
    return heap.pop() == 1 && heap.pop() == 2 && heap.pop() == 4 && heap.pop() == 5 && heap.size() == 0;
}