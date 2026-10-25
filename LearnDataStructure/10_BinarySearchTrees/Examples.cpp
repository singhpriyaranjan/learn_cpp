#include "Examples.h"
#include <iostream>
#include <memory>
#include <vector>

namespace
{
struct Node { int key; std::unique_ptr<Node> left, right; explicit Node(int v) : key(v) {} };
void insert(std::unique_ptr<Node>& node, int key)
{
    if (!node) { node = std::make_unique<Node>(key); return; }
    if (key < node->key) insert(node->left, key); else if (key > node->key) insert(node->right, key);
}
bool contains(const Node* node, int key)
{
    while (node) { if (key == node->key) return true; node = key < node->key ? node->left.get() : node->right.get(); }
    return false;
}
void inorder(const Node* node, std::vector<int>& output) { if (!node) return; inorder(node->left.get(), output); output.push_back(node->key); inorder(node->right.get(), output); }
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: insert-search, all\n"; return 0; }
    if (choice != "all" && choice != "insert-search") { std::cerr << "Unknown example\n"; return 2; }
    std::unique_ptr<Node> root; for (int value : {8, 3, 10, 1, 6}) insert(root, value);
    std::vector<int> sorted; inorder(root.get(), sorted); std::cout << "Inorder:"; for (int v : sorted) std::cout << ' ' << v;
    std::cout << "\ncontains(6)=" << std::boolalpha << contains(root.get(), 6) << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    std::unique_ptr<Node> root; insert(root, 5); insert(root, 3); insert(root, 7); insert(root, 3);
    std::vector<int> order; inorder(root.get(), order);
    return order == std::vector<int>({3, 5, 7}) && contains(root.get(), 7) && !contains(root.get(), 9);
}