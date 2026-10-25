# 09 Trees

## Build and Run

From the repository root: configure with `cmake -S 09_Trees -B build/trees -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/trees --config Debug`, and test with `ctest --test-dir build/trees -C Debug --output-on-failure`. Run `trees traversal`; break at BFS dequeue and inspect pending nodes.

Trees model hierarchy and branching relationships. Nodes own their children here through `unique_ptr`; the root is stack-owned and the descendants are released recursively at scope exit.

```text
       1  depth 0
      / \
     2   3  leaves, depth 1
```

Preorder DFS and breadth-first traversal are both $O(n)$ time; BFS uses $O(w)$ queue space where $w$ is maximum width, and recursive DFS uses $O(h)$ call-stack space for height $h$. Empty roots are valid. Deeply skewed trees can overflow recursive call stacks; ownership must remain acyclic. Run `trees traversal`; break on the queue pop and compare node depth mentally. `std::map`/`std::set` are ordered associative containers, not general tree-node APIs, and their implementation is not mandated. Trees support syntax, hierarchy, and indexes; they are poor for flat scans. Exercises: compute height, all DFS orders, and detect a path. BST ordering is covered next.

## PDF Alignment

The PDF's tree-node and DFS/BFS examples appear around pp. 168-202, with further tree/recursion material around pp. 329-335. The C++ example focuses on traversal order and call/queue state; ownership and standard-container comparisons are additions for this course.