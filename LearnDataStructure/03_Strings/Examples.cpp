#include "Examples.h"
#include <algorithm>
#include <iostream>

namespace
{
bool isPalindrome(const std::string& text)
{
    std::size_t left = 0;
    std::size_t right = text.size();
    while (left < right)
    {
        --right;
        if (text[left] != text[right]) return false;
        ++left;
    }
    return true;
}
std::string reverseText(std::string text)
{
    std::reverse(text.begin(), text.end());
    return text;
}
}

int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: strings, all\n"; return 0; }
    if (choice != "all" && choice != "strings") { std::cerr << "Unknown example\n"; return 2; }
    const std::string word = "level";
    const char legacy[] = "safe";
    std::cout << "C string length=" << sizeof(legacy) - 1 << ", palindrome="
              << std::boolalpha << isPalindrome(word) << ", reverse=" << reverseText(word) << '\n';
    return 0;
}
bool TopicExamples::checksPass() const
{
    return isPalindrome("") && isPalindrome("a") && isPalindrome("level") &&
           !isPalindrome("data") && reverseText("abc") == "cba";
}