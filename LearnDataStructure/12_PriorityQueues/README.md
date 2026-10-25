# 12 Priority Queues

## Build and Run

From the repository root: configure with `cmake -S 12_PriorityQueues -B build/priority_queues -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/priority_queues --config Debug`, and test with `ctest --test-dir build/priority_queues -C Debug --output-on-failure`. Run `priority_queues task-order`; inspect the comparator and top task.

A priority queue returns the highest-priority item, not necessarily the oldest. The demo uses `std::priority_queue` with a custom comparator to show the STL interface; the heap mechanics are implemented in the preceding topic.

```text
top -> highest priority task
       remaining tasks arranged by heap ordering, not FIFO order
```

Top is $O(1)$; push and pop are $O(log n)$; storage is $O(n)$. The comparator defines strict weak ordering; reversing its direction changes which item appears at top. Run `priority_queues task-order` and inspect `top()` before popping. The standard adaptor's underlying container and exact layout are not fixed by the interface. Use for event schedulers and simulations; use a FIFO queue when arrival order is the priority. Exercises: add stable tie-breaking and implement a heap-backed task queue from scratch.

## PDF Alignment

The PDF's heap/heapify material (approximately pp. 234-254) is the algorithmic foundation for this topic. The notes do not directly specify the C++ priority-queue adaptor or comparator contract; this guide adds those C++17 concepts and adapts heap ordering to a task example.