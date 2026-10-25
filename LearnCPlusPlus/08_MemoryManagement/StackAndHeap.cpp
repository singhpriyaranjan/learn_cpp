#include "StackAndHeap.h"

#include <iostream>
#include <memory>

class NumberBox
{
public:
    explicit NumberBox(int value) : value_{value}
    {
        std::cout << "NumberBox constructed\n";
    }
    ~NumberBox() { std::cout << "NumberBox destroyed\n"; }
    int value() const { return value_; }

private:
    int value_;
};

void StackAndHeapExample::run()
{
    // Demonstrates automatic storage and dynamic storage. Local objects have
    // scope-bound lifetimes; dynamic objects live until their owner releases them.
    // `make_unique` is introduced here as the safe owner for a dynamic object.
    NumberBox localBox{3};
    auto dynamicBox{std::make_unique<NumberBox>(8)};
    std::cout << "Local value: " << localBox.value() << '\n';
    std::cout << "Dynamic value: " << dynamicBox->value() << '\n';

    // The local is destroyed at function exit; unique_ptr then deletes its
    // object. Avoid raw owning pointers; the next lesson shows manual new/delete.
    // Expected lifetime: both boxes are destroyed automatically at scope exit.
}