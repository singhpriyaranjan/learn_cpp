# 02 Arrays

## Build and Run

From the repository root: configure with `cmake -S 02_Arrays -B build/arrays -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/arrays --config Debug`, and test with `ctest --test-dir build/arrays -C Debug --output-on-failure`. Run `arrays dynamic`; break at `grow` and inspect the old/new capacity.

Arrays solve indexed storage and fast traversal with adjacent elements. This module implements a small integer `DynamicArray`; fixed arrays and two-dimensional arrays are also demonstrated as standard C++ representations.

```text
index:  0   1   2   3
       [10][20][30][  ]  capacity is reserved contiguous storage
```

The owner is `unique_ptr<int[]>`; resizing allocates a larger block, copies live elements, then releases the old block. Insert shifts a suffix and erase closes the gap. Random access is $O(1)$; search is $O(n)$; insertion/deletion at an arbitrary index is $O(n)$ due to shifting. Append is amortized $O(1)$ under geometric growth, with an occasional $O(n)$ resize. Storage is $O(capacity)$.

Empty arrays and invalid indices are handled explicitly with `std::out_of_range`; duplicates are allowed. Common mistakes include writing past capacity, confusing size with capacity, and retaining pointers across reallocation. Break at `grow`, inspect `size_`/`capacity_`, then step through the shift loop. Build/run with the root commands in [README](../README.md); use `arrays dynamic` or `arrays --help`.

`std::array` has fixed extent; `std::vector` is the general owning dynamic-array choice and offers richer iterator/invalidation contracts. Arrays are useful for tables, buffers, and cache-friendly scans; avoid them when frequent middle insertions dominate. Exercises: implement reverse, remove duplicates in-place, and rotate a rectangular matrix. This representative module does not implement a generic allocator-aware vector.

## PDF Alignment

The PDF repeatedly uses indexed arrays and array-backed algorithms, including the early examples and later stack, queue, and heap material. The `DynamicArray` here translates that contiguous-storage model into explicit C++17 ownership, size/capacity tracking, growth, and invalidation explanations rather than copying the PDF's Java syntax.