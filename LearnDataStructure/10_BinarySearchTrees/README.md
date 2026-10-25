# 10 Binary Search Trees

## Build and Run

From the repository root: configure with `cmake -S 10_BinarySearchTrees -B build/binary_search_trees -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/binary_search_trees --config Debug`, and test with `ctest --test-dir build/binary_search_trees -C Debug --output-on-failure`. Run `binary_search_trees insert-search`; inspect the current node at each key comparison.

A BST keeps smaller keys left and larger keys right, enabling ordered lookup and traversal without storing elements contiguously.

```text
       8
      / \
     3  10
   /  \
  1    6
```

Search/insert take $O(h)$ time and $O(h)$ recursive insertion stack; with balanced height $h=O(log n)$, but a sorted insertion sequence can produce $h=O(n)$. Inorder is $O(n)$ and yields sorted unique keys. This sample ignores duplicate keys and owns nodes with `unique_ptr`; empty search is safe. Deletion, predecessor/successor, and balancing remain exercises. Run `binary_search_trees insert-search`; break at the comparison and follow ownership through recursion. `std::set`/`std::map` provide ordered lookup with specified complexity, but the standard does not require a particular balancing tree. Use for ordered queries; avoid unbalanced BSTs when adversarial order is possible. Exercises: erase leaf/one-child/two-child nodes, find min/max, compare sorted/reverse input.

## PDF Alignment

The PDF provides general tree traversal and recursion examples (approximately pp. 168-202), but no dedicated binary-search-tree section was found. This module extends those foundations with the BST ordering invariant and C++ ownership; deletion and balancing remain clearly labeled exercises.