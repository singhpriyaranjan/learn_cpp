# 14 Graphs

## Build and Run

From the repository root: configure with `cmake -S 14_Graphs -B build/graphs -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/graphs --config Debug`, and test with `ctest --test-dir build/graphs -C Debug --output-on-failure`. Run `graphs bfs`; inspect the queue and visited set as vertices are discovered.

Graphs represent relationships that are not necessarily hierarchical. This directed, unweighted example uses adjacency lists: each vertex stores its outgoing neighbors.

```text
0 ---> 1      2 ---> 3
 \---------->2
```

BFS takes $O(V+E)$ time and $O(V)$ auxiliary space because each reachable vertex and edge is processed a bounded number of times. The representation costs $O(V+E)$; an adjacency matrix instead costs $O(V^2)$ space and offers constant-time edge queries. The traversal marks vertices when enqueued, preventing repeated work on cycles. Invalid vertex indices are rejected by `at`. Run `graphs bfs`; inspect the queue and visited vector. Applications include dependency, route, and network analysis. This slice covers directed BFS; DFS, cycle detection, topological ordering, weights, and shortest paths are explicit exercises. Matrix/list choice depends on graph density and query workload.

## PDF Alignment

The PDF's graph representation and traversal examples appear around pp. 255-286, including adjacency-list traversal with queue/stack state. This module implements a C++ adjacency list and BFS; the other listed graph algorithms remain explicitly scoped as exercises or later expansions.