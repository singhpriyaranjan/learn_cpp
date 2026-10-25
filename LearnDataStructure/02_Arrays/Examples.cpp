#include "Examples.h"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

namespace
{
class DynamicArray
{
public:
    void insert(std::size_t index, int value)
    {
        if (index > size_) throw std::out_of_range("insert index");
        if (size_ == capacity_) grow();
        for (std::size_t i = size_; i > index; --i) data_[i] = data_[i - 1];
        data_[index] = value;
        ++size_;
    }
    void erase(std::size_t index)
    {
        if (index >= size_) throw std::out_of_range("erase index");
        for (std::size_t i = index; i + 1 < size_; ++i) data_[i] = data_[i + 1];
        --size_;
    }
    int at(std::size_t index) const
    {
        if (index >= size_) throw std::out_of_range("array index");
        return data_[index];
    }
    std::size_t size() const { return size_; }
private:
    void grow()
    {
        const std::size_t nextCapacity = capacity_ == 0 ? 2 : capacity_ * 2;
        auto replacement = std::make_unique<int[]>(nextCapacity);
        for (std::size_t i = 0; i < size_; ++i) replacement[i] = data_[i];
        data_ = std::move(replacement);
        capacity_ = nextCapacity;
    }
    std::unique_ptr<int[]> data_;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
};
}

int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: dynamic, all\n"; return 0; }
    if (choice != "all" && choice != "dynamic") { std::cerr << "Unknown example\n"; return 2; }
    DynamicArray values;
    values.insert(0, 10); values.insert(1, 30); values.insert(1, 20); values.erase(0);
    std::cout << "DynamicArray size=" << values.size() << ": ";
    for (std::size_t i = 0; i < values.size(); ++i) std::cout << values.at(i) << ' ';
    std::cout << "\nContiguous storage; insertion shifts suffix elements.\n";
    return 0;
}

bool TopicExamples::checksPass() const
{
    DynamicArray values;
    values.insert(0, 4); values.insert(1, 9); values.insert(1, 6); values.erase(1);
    return values.size() == 2 && values.at(0) == 4 && values.at(1) == 9;
}