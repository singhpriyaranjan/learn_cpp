# 18 Problems

## Build and Run

From the repository root: configure with `cmake -S 18_Problems -B build/problems -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/problems --config Debug`, and test with `ctest --test-dir build/problems -C Debug --output-on-failure`. Run `problems pair-sum`; debug the complement lookup before inserting the current value.

Practice is organized as prompts first and reference implementations separately. Start with the problem and constraints, write tests for empty/single/duplicate cases, and only then inspect `solutions.cpp`.

## Easy: Pair Sum

Given an integer sequence and a target, determine whether two distinct positions sum to the target. Example: `[2, 7, 11, 15]`, target `9` -> true. Duplicates are valid only when they occur at separate positions. Expected average time $O(n)$ and extra space $O(n)$ with hashing; a sort-and-two-pointer approach takes $O(n log n)$ and can alter ordering unless copied.

Hints: for each value, ask whether its complement has already appeared. Avoid using the same element twice, and compute complements without signed overflow.

Run `problems pair-sum`; tests cover duplicate values, a missing answer, singleton input, and normal input. The solution is separate in `solutions.cpp`. Debug at complement calculation and set insertion.

## More Practice

Easy: array traversal, valid parentheses, list middle. Medium: reverse a list, graph cycle detection, sliding-window maximum. Advanced: merge sorted lists, topological ordering, range queries, and a trie autocomplete. For each, state constraints and expected time/space before implementation.

## PDF Alignment

Problem patterns are adapted conceptually from the PDF's array, stack/queue, tree, heap, graph, trie, and Fenwick examples. Prompts and C++17 solutions here are original; linked-list, Union-Find, and other topics not directly covered by the notes are clearly course extensions.