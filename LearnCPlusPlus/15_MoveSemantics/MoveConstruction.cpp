#include "MoveConstruction.h"

#include <iostream>
#include <string>
#include <utility>

class Message
{
public:
    explicit Message(std::string text) : text_{std::move(text)} {}
    Message(const Message& other) : text_{other.text_}
    {
        std::cout << "Copy constructor\n";
    }
    Message(Message&& other) noexcept : text_{std::move(other.text_)}
    {
        std::cout << "Move constructor\n";
    }
    const std::string& text() const { return text_; }

private:
    std::string text_;
};

void MoveConstructionExample::run()
{
    // Demonstrates moving ownership of a string buffer instead of copying it.
    // A move constructor accepts T&&; std::move makes an expression eligible to move.
    Message original{"A message with some text"};
    Message moved{std::move(original)};
    std::cout << "Destination text: " << moved.text() << '\n';

    // The moved-from object remains valid but its value is unspecified. Do not
    // assume it is empty. Mark moves noexcept when they truly cannot throw.
    // Expected: Move constructor, then the original text.
}