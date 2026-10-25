# C++ Data Structures Learning Project

This repository is a debugger-first course for an experienced C++ developer who wants to understand how data structures work, not only how to call their Standard Library interfaces. The learning sequence is:

**Problem and concept -> memory representation -> from-scratch implementation -> operations and edge cases -> debugging -> complexity -> STL comparison -> applications -> exercises**

## Project Status

This repository is being implemented as a runnable C++17 course across all 18 topics. The curriculum, dependency map, build architecture, naming conventions, debugging approach, and test strategy below remain the project blueprint. Each topic will have a runnable navigator, an implementation module, a separate invariant test, and a topic guide. Large topics use a representative implementation plus explicitly identified extension exercises rather than pretending to cover every advanced variant in production depth.

The attached `DSA Notes X CodeWithNishchal 2.pdf` is used as a conceptual reference alongside `prompt.md`. The notes are Java-oriented; examples here are original C++17 implementations and explanations of the same applicable concepts, not copied Java code or PDF prose. Each topic guide identifies direct PDF coverage and project extensions.

## Curriculum

| Topic | Main concepts and implementations | STL connection / outcome |
| --- | --- | --- |
| `01_Foundations` | Big-O; time and space; recursion; pointers and references; stack and heap; contiguous and non-contiguous storage; cache locality; ownership and lifetime; templates; iterators | Build the vocabulary and debugging skills needed by every later topic |
| `02_Arrays` | Static and dynamic arrays; traversal, search, insertion, deletion, resizing; multidimensional arrays; custom `DynamicArray` | Compare with `std::array` and `std::vector` |
| `03_Strings` | Character arrays and null termination; traversal; comparison; substring concepts; common string problems | `std::string` and safe string handling |
| `04_LinkedLists` | Singly, doubly, and circular lists; insertion, deletion, search, reversal, middle node, cycle detection | Compare with `std::forward_list` and `std::list` |
| `05_Stacks` | Stack behavior; array and linked implementations; push, pop, top; expression evaluation; balanced parentheses | `std::stack` adaptor and its underlying container |
| `06_Queues` | Queue behavior; array, linked, and circular queues; enqueue and dequeue | `std::queue` adaptor |
| `07_Deques` | Double-ended operations and circular-buffer concepts | `std::deque` |
| `08_HashTables` | Hash functions; buckets; collisions; separate chaining; open addressing; linear and quadratic probing; load factor; rehashing | Compare with `std::unordered_map` and `std::unordered_set` |
| `09_Trees` | Tree terminology; nodes and relationships; depth and height; recursive representation; DFS and BFS | Tree traversal foundations for ordered and specialized trees |
| `10_BinarySearchTrees` | Insert, search, delete, min/max, predecessor/successor, traversals; balanced versus unbalanced behavior | Explain the ordered-tree concepts behind `std::map` and `std::set`, without assuming a mandated implementation |
| `11_Heaps` | Binary min/max heaps; array representation; insertion; heapify; deletion; heap construction; heap sort | Understand the heap primitive used by priority queues |
| `12_PriorityQueues` | Priority behavior; heap-backed implementation; custom ordering | `std::priority_queue` and comparator semantics |
| `13_Tries` | Prefix trees; insert, lookup, delete, prefix search, autocomplete; memory trade-offs | Apply tries to dictionaries and prefix lookup |
| `14_Graphs` | Vertices and edges; directed, undirected, and weighted graphs; adjacency matrix/list; BFS, DFS, cycle detection, topological sort, shortest-path fundamentals | Choose a representation based on graph density and workload |
| `15_DisjointSets` | Sets; find and union; path compression; union by rank/size; cycle detection | Union-Find / Disjoint Set Union for dynamic connectivity |
| `16_STL_DataStructures` | Selection and trade-offs across the standard containers and adaptors | `array`, `vector`, `deque`, `list`, `forward_list`, `stack`, `queue`, `priority_queue`, `set`, `map`, `unordered_set`, `unordered_map` |
| `17_Advanced_DataStructures` | AVL trees; Red-Black tree concepts; segment trees; Fenwick trees; sparse tables; LRU cache; Bloom filter concepts | Advanced range-query, balancing, caching, and membership techniques |
| `18_Problems` | Easy, medium, and advanced exercises grouped by prerequisite/topic; prompts separated from solutions | Practice independently before reading a solution |

Every topic README will answer what problem a structure solves, how it is represented in memory, its operations and complexity, edge cases and common mistakes, how to build/run/debug it, STL alternatives, trade-offs, applications, and exercises. Complexity explanations will say why the bound occurs and distinguish best, average (when meaningful), and worst cases.

## PDF Alignment

PDF page numbers below refer to the attached 422-page document. These are conceptual references, not claims that the PDF uses C++ or prescribes the implementations in this repository.

| Project topics | PDF coverage and how this course uses it |
| --- | --- |
| Foundations | Recursion and call-depth/recursion-tree analysis (roughly pp. 27-44) inform the recursive examples and complexity explanations. Ownership, C++ storage duration, templates, and iterators are added for this C++ course. |
| Arrays and Strings | Array-based examples recur in the early notes and throughout later implementations; string/character examples appear in the early pages and trie material. The course adds explicit C++ array ownership, capacity, invalidation, and `std::string` comparisons. |
| Linked Lists | No dedicated linked-list section was found in the PDF text. Node ownership, RAII, and list operations are course additions. |
| Stacks, Queues, Deques | Stack/queue/deque and array-deque examples appear around pp. 122-149; queue-based graph traversal appears in the graph section. Implementations here translate the operations into C++17 and explain the different STL interfaces. |
| Hash Tables | The notes use Java `HashMap` in examples (notably around pp. 74-84 and in trie discussions), but do not present hash-table collision handling as a complete data-structure lesson. Chaining, probing, load factor, and rehashing are course additions. |
| Trees and Binary Search Trees | Tree traversal and recursion examples appear around pp. 168-202 and pp. 329-335. The ordered BST invariants, deletion cases, and balancing discussion are extended here. |
| Heaps and Priority Queues | Heap/heapify examples appear around pp. 234-254, including uses alongside queue-like work. The C++ course adds heap ownership, STL comparisons, and explicit comparator contracts. |
| Tries | Trie nodes, word insertion, and lookup appear around pp. 287-301. The course reimplements these ideas with C++ ownership and documents alphabet and memory trade-offs. |
| Graphs and Disjoint Sets | Graph representations and traversal appear around pp. 255-286. Union-Find is not directly covered in the PDF text and is a course extension. |
| Advanced Data Structures | Fenwick/Binary Indexed Tree material appears around pp. 374-393 and informs the implemented prefix-sum example. AVL/Red-Black concepts, segment trees, sparse tables, LRU caches, and Bloom filters are additional curriculum topics. |
| STL Data Structures and Problems | The PDF's Java APIs are used only as conceptual comparison points; this course explains the C++ Standard Library contracts independently. Exercises extend the PDF's patterns and are written as original prompts. |

Page ranges are approximate section locations based on extracted PDF text. When a structure is only used in an example or is not covered as a topic, the guide says so rather than implying complete PDF treatment.

## Repository Architecture

```text
CppDataStructures/
|-- README.md
|-- CMakeLists.txt
|-- cmake/
|   `-- ProjectOptions.cmake       # Shared compiler and warning settings, if needed
|-- 01_Foundations/
|   |-- README.md
|   |-- CMakeLists.txt
|   |-- main.cpp                   # Navigator only; accepts an optional example name
|   |-- examples/
|   |   |-- BigOExample.h/.cpp
|   |   |-- MemoryModelExample.h/.cpp
|   |   |-- PointerAndOwnershipExample.h/.cpp
|   |   |-- RecursionExample.h/.cpp
|   |   |-- TemplatesAndIteratorsExample.h/.cpp
|   |   `-- CacheLocalityExample.h/.cpp
|   `-- tests/
|       |-- CMakeLists.txt
|       `-- foundations_tests.cpp
|-- 02_Arrays/                     # README, CMakeLists, main, examples, include, src, tests
|-- 03_Strings/                    # Same topic-level layout
|-- 04_LinkedLists/                # Same topic-level layout
|-- 05_Stacks/                     # Same topic-level layout
|-- 06_Queues/                     # Same topic-level layout
|-- 07_Deques/                     # Same topic-level layout
|-- 08_HashTables/                 # Same topic-level layout
|-- 09_Trees/                      # Same topic-level layout
|-- 10_BinarySearchTrees/          # Same topic-level layout
|-- 11_Heaps/                      # Same topic-level layout
|-- 12_PriorityQueues/             # Same topic-level layout
|-- 13_Tries/                      # Same topic-level layout
|-- 14_Graphs/                     # Same topic-level layout
|-- 15_DisjointSets/               # Same topic-level layout
|-- 16_STL_DataStructures/         # README, CMakeLists, main, examples, tests
|-- 17_Advanced_DataStructures/    # README, CMakeLists, main; subfolder per structure
|   `-- <structure>/               # README, examples, implementation, tests
`-- 18_Problems/
	|-- README.md
	|-- CMakeLists.txt
	`-- <topic>/
		|-- README.md               # Problem, examples, constraints, hints, complexity
		`-- solutions.cpp           # Kept separate from the unsolved prompt
```

Each of topics `02_Arrays` through `15_DisjointSets` contains `README.md`, `CMakeLists.txt`, `main.cpp`, `examples/`, `include/`, `src/`, and `tests/`. Each major topic receives its own `README.md`, `main.cpp`, and `CMakeLists.txt`. Significant subtopics have focused classes and separate header/source files where that separation improves understanding. Tiny examples may remain together only when splitting them would obscure the lesson.

### Topic Navigator and Selective Execution

Each topic's `main.cpp` only prints its heading, creates example objects, and dispatches execution. It does not contain data-structure implementations. A consistent command-line convention is used:

```text
topic_name             # Run all examples in the topic, in curriculum order
topic_name singly      # Run only the named example (example alias shown by --help)
topic_name --help      # List selectable examples
```

Each example class has a small `run()` method and private operation-sized demonstration methods (for example, insertion, deletion, search, traversal, and edge cases). A breakpoint in one example should not require stepping through earlier examples.

## Topic Dependency Map

```text
Foundations
|-- Arrays
|   |-- Stacks
|   |-- Queues
|   |-- Deques
|   |-- Heaps --> Priority Queues
|   `-- Advanced range structures (Segment Tree, Fenwick Tree, Sparse Table)
|-- Linked Lists
|   |-- Stacks
|   `-- Queues
|-- Trees
|   |-- Binary Search Trees --> AVL / Red-Black tree concepts
|   |-- Heaps
|   `-- Tries
|-- Hash Tables
|   `-- LRU Cache (with linked-list concepts)
|-- Strings --> Tries
|-- Graphs --> Disjoint Sets
`-- STL Data Structures (informed by the corresponding structures above)

Problems draw on all completed topics. Bloom Filter concepts build on hashing.
```

Foundations is a prerequisite for every branch. Arrays, linked lists, trees, hashing, and graphs can then be learned largely independently. Some topics have more than one useful prerequisite; those are stated in the topic README rather than forcing an artificial single path.

## Build Architecture

- The root `CMakeLists.txt` defines one C++17 project, enables CTest, and adds each topic directory. It provides an aggregate build for the complete course.
- Every topic `CMakeLists.txt` defines a topic executable and its source files. It can also be configured directly from that topic folder, so the learner can build and debug one subject in isolation.
- Executable target names use stable lowercase snake case, such as `foundations`, `arrays`, and `linked_lists`.
- Topic test subdirectories add separate test executables and register them with CTest. Learning demonstrations and automated tests remain separate.
- Debug builds are the default learning configuration. The instructions cover Visual Studio multi-configuration generators as well as single-configuration generators such as Ninja; use `Debug` configuration and preserve debug symbols. No external test framework is required initially; a small assertion-based test harness keeps the project dependency-free.
- Only C++17 features are required by the primary examples. A newer-standard alternative may be discussed in documentation, but it does not raise the baseline.

Build and run the complete course:

```powershell
# Configure and build the whole repository in Debug mode
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug

# Run all registered tests
ctest --test-dir build -C Debug --output-on-failure

# Configure/build just one topic from its own directory
cmake -S 01_Foundations -B build/foundations -DCMAKE_BUILD_TYPE=Debug
cmake --build build/foundations --config Debug
ctest --test-dir build/foundations -C Debug --output-on-failure

# Run a topic and select one example
./build/01_Foundations/foundations --help
./build/01_Foundations/foundations recursion
```

For Visual Studio generators, `--config Debug` selects the configuration; `CMAKE_BUILD_TYPE` is ignored by multi-configuration generators. Each topic README will give exact commands for its executable and examples.

### Qt Creator / qmake

`LearnDataStructure.pro` is the root `TEMPLATE = subdirs` project. Its `SUBDIRS` list includes each topic directory, and qmake resolves each child project as `<topic>/<topic>.pro`. Every child `.pro` builds that topic's standalone C++17 console executable; open a child `.pro` directly in Qt Creator to work on one topic. Select a Qt Creator kit with a C++17-capable compiler. Qt libraries are not required by the examples. CMake remains the route for the registered automated tests.

## Naming and File Conventions

- Topic folders use two-digit curriculum ordering and PascalCase words: `04_LinkedLists`.
- C++ types use `PascalCase`; functions and local variables use `lowerCamelCase`; private data members use a trailing underscore, such as `head_`.
- Example classes end in `Example`, such as `SinglyLinkedListExample`, and expose `run()` as the focused demonstration entry point.
- Implementations use descriptive operation names (`insertFront`, `eraseValue`, `findMiddle`) and explicit control flow suited to stepping in a debugger.
- Headers use `#pragma once`; public interfaces are declared in headers, with non-template implementations in `.cpp` files. Templates stay in headers unless an explicit-instantiation lesson is intended.
- Each from-scratch container documents ownership and copy/move behavior. Raw pointers are used when pointer relationships are the lesson; ownership is explicit and all allocations are released. Prefer value semantics/RAII where they teach the same concept more safely.
- Exercise prompts and their solutions are separate so learners can attempt the task without seeing the answer first.

## Debugging Strategy

Examples are written to expose state rather than hide it behind compressed expressions. Use named `current`, `previous`, `parent`, and index variables; keep mutation steps on separate lines; and avoid unnecessary abstractions in the first implementation.

Each topic README will identify concrete breakpoint checkpoints appropriate to the structure:

1. Allocation or object construction.
2. Link, index, or invariant update.
3. Traversal, search, or recursive descent.
4. Removal, replacement, or rebalancing.
5. Destruction and cleanup.

Inspect node fields, pointer targets, container size/capacity, loop indices, and invariants at each stop. For recursive algorithms, inspect arguments and local state in every call-stack frame, then follow returns while noting how partial results combine. For copy/move-aware structures, inspect the source and destination before and after the operation and at destruction. Examples include empty, single-element, duplicate, missing-value, boundary, and destruction cases as applicable. Any intentionally incorrect implementation must be isolated, clearly labeled, and never used as the normal path.

## Testing Strategy

Automated tests verify behavior independently of the tutorial output. Tests are grouped by topic and registered with CTest. Each applicable structure covers:

- Normal operations and the structure's invariants.
- Empty and single-element states.
- Boundary positions, duplicates, and missing values.
- Capacity growth/limits or resize behavior when applicable.
- Copy, move, and destruction behavior for owning containers.
- Invalid input or rejected operations, with the chosen contract documented.

Tests should be deterministic and small enough to debug interactively. More advanced structures add targeted tests for invariants and algorithms (for example, heap ordering, BST ordering, graph reachability, or union-find connectivity). The teaching executable remains a readable, sequential narrative; tests are not used as a substitute for its demonstrations.

## First Topic: `01_Foundations`

Foundations comes first because every later implementation relies on its shared mental model: complexity describes operation cost; pointers and references express relationships; stack/heap and lifetime explain where objects live and who owns them; recursion and templates recur throughout trees, graphs, and reusable containers; iterators bridge implementations to the STL. Establishing these ideas first makes later pointer mutations and complexity trade-offs easier to reason about and debug.

Every topic guide documents the concepts and representative implementation, expected behavior, build/run commands, debugger checkpoints, complexity, STL connection, applications, and exercises. `18_Problems` collects prompts separately from compact reference solutions.