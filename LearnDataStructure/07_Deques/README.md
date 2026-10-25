# 07 Deques

## Build and Run

From the repository root: configure with `cmake -S 07_Deques -B build/deques -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/deques --config Debug`, and test with `ctest --test-dir build/deques -C Debug --output-on-failure`. Run `deques ring`; inspect front and size at each endpoint update.

A double-ended queue permits insertion and removal at either end. This fixed circular buffer uses modulo indexing and avoids shifting values.

```text
front -> [ ][A][B][ ][ ] <- back; free slots wrap at array boundary
```

Both-end operations are $O(1)$ time, with $O(capacity)$ storage. Full insertion returns false and empty removal throws. Check one-element transitions and wraparound; off-by-one errors often arise when updating front before reading. Run `deques ring`; inspect `front_`/`size_` at each mutation. `std::deque` offers a dynamically managed segmented representation, not a guarantee of this ring layout. Deques are useful for sliding windows and work queues; fixed buffers are unsuitable when capacity is unknown. Exercises: expose both-end peek, add resizing, and implement a monotonic deque for window maximum.

## PDF Alignment

The PDF uses Java's `ArrayDeque` while illustrating double-ended and stack/queue operations around pp. 136-149. This example makes the ring-buffer mechanics visible in C++ and contrasts them with `std::deque`, whose internal representation is not specified by the standard.