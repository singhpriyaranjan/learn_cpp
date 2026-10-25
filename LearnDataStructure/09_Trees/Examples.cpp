#include "Examples.h"
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

namespace
{
struct Node { int value; std::unique_ptr<Node> left, right; explicit Node(int v) : value(v) {} };
void preorder(const Node* node, std::vector<int>& out) { if (!node) return; out.push_back(node->value); preorder(node->left.get(), out); preorder(node->right.get(), out); }
std::vector<int> breadthFirst(const Node* root)
{
    std::vector<int> out; std::queue<const Node*> pending; if (root) pending.push(root);
    while (!pending.empty()) { const Node* node = pending.front(); pending.pop(); out.push_back(node->value); if (node->left) pending.push(node->left.get()); if (node->right) pending.push(node->right.get()); }
    return out;
}
}
int TopicExamples::run(int argc, char** argv) const
{
    const std::string choice = argc > 1 ? argv[1] : "all";
    if (choice == "--help") { std::cout << "Examples: traversal, all\n"; return 0; }
    if (choice != "all" && choice != "traversal") { std::cerr << "Unknown example\n"; return 2; }
    Node root(1); root.left = std::make_unique<Node>(2); root.right = std::make_unique<Node>(3);
    std::cout << "BFS order:"; for (int value : breadthFirst(&root)) std::cout << ' ' << value; std::cout << '\n'; return 0;
}
bool TopicExamples::checksPass() const
{
    Node root(1); root.left = std::make_unique<Node>(2); root.right = std::make_unique<Node>(3);
    std::vector<int> order; preorder(&root, order);
    return order == std::vector<int>({1, 2, 3}) && breadthFirst(&root) == order && breadthFirst(nullptr).empty();
}