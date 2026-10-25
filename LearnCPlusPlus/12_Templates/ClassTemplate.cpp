#include "ClassTemplate.h"

#include <iostream>
#include <string>
#include <utility>

template <typename T>
class Box
{
public:
    explicit Box(T value) : value_{std::move(value)} {}
    const T& value() const { return value_; }

private:
    T value_;
};

void ClassTemplateExample::run()
{
    // Demonstrates a class template whose stored value type is a parameter.
    // Templates enable reusable type-safe containers without using void pointers.
    // Syntax: Box<Type> name{value};
    const Box<int> numberBox{25};
    const Box<std::string> labelBox{"lesson"};
    std::cout << "Number box: " << numberBox.value() << '\n';
    std::cout << "Text box: " << labelBox.value() << '\n';

    // Each specialization has a concrete type checked by the compiler.
    // Keep template definitions visible where instantiation needs them.
    // Expected output: Number box: 25; Text box: lesson.
}