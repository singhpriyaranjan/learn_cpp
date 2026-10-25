#include "Examples.h"
#include <array>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace
{
class Trie
{
    struct Node { std::array<std::unique_ptr<Node>, 26> children{}; bool terminal = false; };
    Node root_;
    static std::size_t index(char ch) { if (ch < 'a' || ch > 'z') throw std::invalid_argument("trie accepts lowercase a-z"); return static_cast<std::size_t>(ch - 'a'); }
public:
    void insert(const std::string& word)
    {
        Node* current = &root_;
        for (char ch : word) { auto& child = current->children[index(ch)]; if (!child) child = std::make_unique<Node>(); current = child.get(); }
        current->terminal = true;
    }
    bool contains(const std::string& word) const
    {
        const Node* current = &root_;
        for (char ch : word) { const auto& child = current->children[index(ch)]; if (!child) return false; current = child.get(); }
        return current->terminal;
    }
};
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: prefix, all\n"; return 0; }
    if (choice != "all" && choice != "prefix") { std::cerr << "Unknown example\n"; return 2; }
    Trie words; words.insert("tree"); words.insert("trie");
    std::cout << "contains(tree)=" << std::boolalpha << words.contains("tree") << ", contains(tr)=" << words.contains("tr") << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    Trie words; words.insert(""); words.insert("tree"); words.insert("trie");
    return words.contains("") && words.contains("tree") && !words.contains("tr") && !words.contains("track");
}