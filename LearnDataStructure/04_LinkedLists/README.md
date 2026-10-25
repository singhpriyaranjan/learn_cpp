# 04 Linked Lists

## Build and Run

From the repository root: configure with `cmake -S 04_LinkedLists -B build/linked_lists -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/linked_lists --config Debug`, and test with `ctest --test-dir build/linked_lists -C Debug --output-on-failure`. Run `linked_lists singly`; break at the ownership moves in `reverse` and inspect `head_`.

Linked lists avoid shifting an entire contiguous suffix when linking/unlinking at a known node, at the cost of pointer chasing and per-node allocation.

```text
head -> [10 | next] -> [20 | next] -> [30 | null]
          heap nodes; links are not adjacent by contract
```

This slice implements a singly linked list with `unique_ptr` ownership and iterative reversal. Each node owns its successor; destruction follows the chain automatically. Front insertion is $O(1)$; search and traversal are $O(n)$; reversing is $O(n)$ time and $O(1)$ auxiliary pointers. Empty lists and reversal are safe. Beware losing the successor before relinking, cycles in owning chains, and recursive destruction of very long chains.

Use `linked_lists singly`; break at the `next` move in `reverse` and inspect `head_`, `previous`, and `next`. STL comparisons are `std::forward_list` and `std::list`; the standard does not promise a particular internal node layout beyond specified behavior. Linked structures suit frequent local edits when a node/iterator is already known, but are often poor for indexed access and cache-sensitive scans. Exercises: erase a value, find middle, detect cycles, then implement doubly/circular variants. Those variants and `std::list` invalidation details are extension work.

## PDF Alignment

No dedicated linked-list lesson was found in the PDF text. This topic is a course extension: its singly linked list is implemented independently in C++ to teach node ownership, pointer relinking, and destruction, with the PDF's array/stack/queue patterns used only as contrast.