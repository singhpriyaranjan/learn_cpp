# 15 Disjoint Sets

## Build and Run

From the repository root: configure with `cmake -S 15_DisjointSets -B build/disjoint_sets -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/disjoint_sets --config Debug`, and test with `ctest --test-dir build/disjoint_sets -C Debug --output-on-failure`. Run `disjoint_sets connectivity`; step through parent rewrites in `find`.

Disjoint Set Union maintains a partition under connectivity merges. It is useful when components only merge, not split.

```text
parent: [0, 0, 0, 3]   {0,1,2} and {3}
find(x) follows parent links to a representative
```

This implementation applies path compression and union by size. Operations are amortized $O(\alpha(n))$ over a sequence, where inverse Ackermann growth is effectively constant for practical sizes; one uncompressed find can traverse tree height. Storage is $O(n)$. Invalid indices throw; merging already connected values returns false. Run `disjoint_sets connectivity`; step through parent rewrites in `find`. It supports connectivity and Kruskal-style cycle checks, but not deletions/splitting. Exercises: expose component count, implement union by rank, and detect an edge that closes a cycle.

## PDF Alignment

The PDF includes graph representations and traversal (approximately pp. 255-286), but no Disjoint Set/Union-Find implementation was found. This topic extends graph connectivity with a from-scratch C++ implementation using path compression and union by size.