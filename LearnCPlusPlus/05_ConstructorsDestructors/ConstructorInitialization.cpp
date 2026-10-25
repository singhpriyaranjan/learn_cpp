#include "ConstructorInitialization.h"

#include <iostream>
#include <string>
#include <utility>

class Book
{
public:
    Book(std::string title, int pages)
        : title_{std::move(title)}, pages_{pages}
    {
        std::cout << "Constructing book: " << title_ << '\n';
    }

    void describe() const
    {
        std::cout << title_ << " has " << pages_ << " pages.\n";
    }

private:
    std::string title_;
    int pages_;
};

void ConstructorInitializationExample::run()
{
    // Demonstrates a parameterized constructor and member initializer list.
    // Constructors establish an object's valid starting state.
    // Syntax: Class(args) : member_{arg} { ... }
    Book book{"C++ Notes", 120};
    book.describe();

    // Members initialize in declaration order, not list order. Initialize every
    // member in the initializer list to avoid uninitialized state.
    // Expected output: Constructing book: C++ Notes; C++ Notes has 120 pages.
}