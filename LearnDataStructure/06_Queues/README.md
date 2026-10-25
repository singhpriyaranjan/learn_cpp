# 06 Queues

## Build and Run

From the repository root: configure with `cmake -S 06_Queues -B build/queues -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/queues --config Debug`, and test with `ctest --test-dir build/queues -C Debug --output-on-failure`. Run `queues circular`; break at the wrapped tail-index calculation.

Queues preserve first-in, first-out order for scheduling and event processing. This module uses a fixed-capacity circular buffer: indices wrap modulo capacity, so removing the front does not shift all remaining values.

```text
head -> [A][B][ ][ ] <- tail wraps around the fixed array
```

The array is embedded in the queue object; `head_` and `size_` distinguish empty from full while making all slots usable. Enqueue/dequeue are $O(1)$ time and the buffer uses $O(capacity)$ space. A full enqueue returns false; empty dequeue throws. Test wraparound, full, empty, and one-item transitions. Break at tail calculation and inspect head and size.

Use `queues circular`. `std::queue` is a FIFO adaptor, not a promise of this exact representation. Queues suit producer-consumer pipelines and breadth-first search; avoid fixed capacity when workload bounds are unknown. Exercises: add a linked queue with explicit ownership, implement a growable ring buffer, and use a queue for level-order traversal. Those variants are extension exercises.

## PDF Alignment

The PDF's array-queue examples appear around pp. 136-144, and its graph BFS uses a FIFO queue later in the graph material. This topic translates the queue behavior into a C++ circular buffer and separately compares it with the `std::queue` adaptor.