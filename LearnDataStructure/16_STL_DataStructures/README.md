# 16 STL Data Structures

## Build and Run

From the repository root: configure with `cmake -S 16_STL_DataStructures -B build/stl_data_structures -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/stl_data_structures --config Debug`, and test with `ctest --test-dir build/stl_data_structures -C Debug --output-on-failure`. Run `stl_data_structures selection`; step through the declarations to compare interfaces.

This topic is a selection guide: choose by required operations and invalidation/lifetime guarantees, not by container name alone. The executable instantiates `array`, `vector`, `deque`, `list`, `forward_list`, stack/queue/priority-queue adaptors, ordered set/map, and unordered set/map.

```text
fixed extent -> array       indexed growable -> vector
both-end access -> deque    ordered keys -> set/map
hash lookup -> unordered_*  restricted access -> adaptors
```

Complexities follow the relevant standard container guarantees: vector indexing is constant and middle insertion linear; associative ordered lookup is logarithmic; unordered lookup is average constant but worst-case linear. `list` insertion at a known iterator is constant, but finding that position is linear. Storage costs include metadata and allocations; contiguous storage often improves locality. Iterators/references can be invalidated by operations specified for each container, so consult the exact container contract. Run `stl_data_structures selection`; compare traversal and mutation workloads. Use `vector` as a default for sequences, not as a universal answer. Exercises: choose containers for an LRU cache, stable ordering, and a sliding window.

## PDF Alignment

The PDF demonstrates Java collection APIs such as `ArrayList`, `ArrayDeque`, and `HashMap`. This topic uses those examples only to motivate container roles, then explains C++17 standard-library interfaces and guarantees independently; Java and C++ container contracts are not interchangeable.