# 11 Heaps

## Build and Run

From the repository root: configure with `cmake -S 11_Heaps -B build/heaps -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/heaps --config Debug`, and test with `ctest --test-dir build/heaps -C Debug --output-on-failure`. Run `heaps min-heap`; step through `siftDown` and the parent/child indices.

A binary heap efficiently exposes an extremum; its complete-tree shape is stored compactly in a vector rather than linked nodes.

```text
array: [1, 2, 9, 7]       parent(i)=(i-1)/2, child(i)=2i+1/2i+2
tree:       1
           / \
          2   9
         /
        7
```

Push and pop are $O(log n)$ from a root-to-leaf sift; reading the root is $O(1)$; storage is $O(n)$. Empty pop throws. This min-heap demonstrates insertion and removal; bottom-up heap construction and heapsort are exercises. Common bugs are wrong child indices and stopping before restoring parent order. Run `heaps min-heap`; inspect swaps in `siftDown`. `std::make_heap` and `std::priority_queue` provide standard alternatives without mandating this exact internal representation. Use heaps for scheduling and repeated min/max extraction, not full sorted traversal.

## PDF Alignment

The PDF's binary-heap and heapify examples appear around pp. 234-254. This implementation expresses the same index/parent-child and sift operations in C++17, with additional ownership, exception, and standard-library contract notes.