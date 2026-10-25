# 17 Advanced Data Structures

## Build and Run

From the repository root: configure with `cmake -S 17_Advanced_DataStructures -B build/advanced_data_structures -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/advanced_data_structures --config Debug`, and test with `ctest --test-dir build/advanced_data_structures -C Debug --output-on-failure`. Run `advanced_data_structures fenwick`; hand-trace the low-bit index updates.

Prerequisites: arrays, trees, asymptotic analysis, and careful index reasoning. This module implements a Fenwick tree (Binary Indexed Tree) for dynamic prefix sums; AVL/Red-Black balancing, segment trees, sparse tables, LRU caches, and Bloom filters are named as next steps rather than falsely represented as implemented.

```text
values: [2, 3, 0, 5]
tree cells store overlapping low-bit-sized ranges
prefixSum(3) combines O(log n) selected cells
```

Point update and prefix query are $O(log n)$; storage is $O(n)$. The API accepts zero-based element indices and a count for half-open prefix `[0,count)`. Bounds are checked. The low bit `i & -i` determines the next responsible range; this implementation expresses negation via unsigned arithmetic. Break at the index increments/decrements and hand-trace a small array. Fenwick trees suit additive updates/prefix sums, not arbitrary range aggregates without additional structure. Run `advanced_data_structures fenwick`. Exercises: range sums, lower-bound search for nonnegative frequencies, and compare against segment tree, sparse table, balanced trees, LRU, and Bloom filter trade-offs.

## PDF Alignment

The PDF includes Fenwick/Binary Indexed Tree material around pp. 374-393; it informs the prefix-sum/update demonstration here. The other advanced structures named in this guide are curriculum extensions and are not represented as implemented merely because they appear in the broader topic list.