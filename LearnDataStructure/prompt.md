# ROLE

Act as a senior C++ engineer, data-structures expert, algorithms instructor, and technical mentor.

Create a structured "C++ Data Structures Learning Project" for an experienced C++ software developer.

Each folder will have a readme file explaining concept present in the sub chapter

The project must teach data structures through:

Concept
    ↓
Memory representation
    ↓
From-scratch implementation
    ↓
Operations
    ↓
Debugging
    ↓
Complexity analysis
    ↓
C++ STL equivalent
    ↓
Real-world use cases
    ↓
Problems and exercises

The objective is NOT simply to demonstrate STL containers.

I want to understand how each data structure works internally, how memory is organized, what its performance characteristics are, and when it should or should not be used.


# PRIMARY REQUIREMENTS

Design the repository around these principles:

1. One folder per major data-structure topic.
2. Separate C++ files for individual subtopics/operations.
3. Every topic folder has its own main.cpp.
4. main.cpp sequentially triggers subtopic examples through corresponding class objects.
5. Every example contains explanatory documentation.
6. Code must be intentionally easy to debug using breakpoints.
7. Implement important structures from scratch before demonstrating their STL equivalents.
8. Explain time and space complexity.
9. Include edge cases and common implementation mistakes.
10. Progress from fundamental to advanced data structures.


# LANGUAGE AND TOOLING

Use:

- Modern C++
- C++17 as the baseline
- CMake
- Standard Library
- Debug builds

Avoid external dependencies unless they provide significant educational value.

Where a newer C++ standard improves an implementation, mention it separately without unnecessarily making the primary example dependent on it.


# REPOSITORY STRUCTURE

Create a structure similar to:

CppDataStructures/
│
├── README.md
├── CMakeLists.txt
│
├── 01_Foundations/
├── 02_Arrays/
├── 03_Strings/
├── 04_LinkedLists/
├── 05_Stacks/
├── 06_Queues/
├── 07_Deques/
├── 08_HashTables/
├── 09_Trees/
├── 10_BinarySearchTrees/
├── 11_Heaps/
├── 12_PriorityQueues/
├── 13_Tries/
├── 14_Graphs/
├── 15_DisjointSets/
├── 16_STL_DataStructures/
├── 17_Advanced_DataStructures/
└── 18_Problems/


# TOPIC FOLDER DESIGN

Each topic gets its own folder.

Example:

04_LinkedLists/
│
├── README.md
├── main.cpp
├── CMakeLists.txt
│
├── SinglyLinkedList.h
├── SinglyLinkedList.cpp
├── DoublyLinkedList.h
├── DoublyLinkedList.cpp
├── CircularLinkedList.h
├── CircularLinkedList.cpp
├── LinkedListProblems.h
└── LinkedListProblems.cpp


# MAIN.CPP DESIGN

Every topic folder must contain its own main.cpp.

main.cpp acts only as the learning navigator.

Example:

int main()
{
    std::cout << "=== Linked Lists ===\n";

    SinglyLinkedListExample singly;
    singly.run();

    DoublyLinkedListExample doubly;
    doubly.run();

    CircularLinkedListExample circular;
    circular.run();

    LinkedListProblems problems;
    problems.run();

    return 0;
}


main.cpp should NOT contain the actual data-structure implementation.

Its responsibilities are:

- initialize the topic
- display useful headings
- instantiate example classes
- trigger demonstrations sequentially


# SELECTIVE EXECUTION

In addition to sequential execution:

    ./linked_lists

support running a specific example where practical:

    ./linked_lists singly
    ./linked_lists doubly
    ./linked_lists problems

This is especially important for debugging.

I should be able to focus on one data structure or operation without stepping through every earlier example.


# SUBTOPIC ORGANIZATION

Each significant subtopic should have a dedicated class and corresponding .h/.cpp files where appropriate.

Typical example:

class SinglyLinkedListExample
{
public:
    void run();

private:
    void demonstrateInsertion();
    void demonstrateDeletion();
    void demonstrateSearch();
    void demonstrateTraversal();
};


Keep individual methods small.

Do not create giant run() functions containing the entire demonstration.


# LEARNING APPROACH

For every data structure, follow this sequence:

1. Problem/Motivation
2. Concept
3. Visual representation
4. Memory representation
5. Node/data definition
6. From-scratch implementation
7. Basic operations
8. Edge cases
9. Debugging
10. Complexity analysis
11. STL equivalent, if available
12. Trade-offs
13. Real-world usage
14. Problems/exercises


# MEMORY REPRESENTATION

Because this is C++, explicitly teach memory behavior.

Where applicable explain:

- stack
- heap
- contiguous memory
- non-contiguous memory
- pointers
- references
- allocation
- deallocation
- ownership
- object lifetime
- cache locality
- iterator/reference invalidation

For example, when comparing:

std::vector

and

std::list

do not stop at Big-O notation.

Explain important practical differences such as memory layout, allocations, locality, traversal behavior, and invalidation rules.


# VISUALIZATION

Use ASCII diagrams inside documentation/comments where useful.

Example:

Singly Linked List

head
 |
 v

+------+-------+    +------+-------+    +------+---------+
|  10  |   o------>|  20  |   o------>|  30  | nullptr |
+------+-------+    +------+-------+    +------+---------+

For trees:

             50
           /    \
         30      70
        /  \    /  \
       20  40  60  80

For graphs:

A ----- B
|       |
|       |
C ----- D

The diagram should help correlate source code with what will be visible in the debugger.


# DEBUG-FIRST DESIGN

Debuggability is a primary requirement.

Every example should make it easy to:

- place breakpoints
- inspect nodes
- inspect pointers
- inspect indices
- inspect container size/capacity
- inspect recursion
- observe allocation/deallocation
- follow traversal
- identify invalid states

Prefer:

Node* current = head_;
Node* previous = nullptr;

instead of compressed, overly clever expressions when the explicit version is easier to debug.


# DEBUG CHECKPOINTS

Documentation should suggest useful breakpoint locations.

Example:

Breakpoint 1:
    Node allocation

Breakpoint 2:
    Pointer linking

Breakpoint 3:
    Traversal loop

Breakpoint 4:
    Node deletion

Breakpoint 5:
    Destructor


For recursive structures, explain what to inspect in the call stack.


# MEMORY SAFETY

From-scratch structures must clearly define ownership.

Explain:

Who owns this node?

Who destroys it?

What happens when the container is copied?

What happens when it is moved?

What happens during destruction?


Where appropriate demonstrate:

- destructor
- Rule of Zero
- Rule of Three
- Rule of Five
- copy constructor
- copy assignment
- move constructor
- move assignment


Do not casually introduce memory leaks or undefined behavior.

If intentionally demonstrating a bug, clearly isolate and label it as an incorrect example.


# COMPLEXITY ANALYSIS

For every important operation explain:

- Time complexity
- Space complexity
- Best case
- Average case, when meaningful
- Worst case
- Why that complexity occurs


For example:

Singly Linked List:

insert_front() -> O(1)
search()       -> O(n)
insert_end()   -> O(n) without tail pointer
delete_value() -> O(n)


Do not merely state Big-O.

Explain why.


# FROM SCRATCH VS STL

For applicable topics teach:

FROM SCRATCH
       ↓
Understand internals
       ↓
Debug internals
       ↓
Analyze complexity
       ↓
C++ STL implementation
       ↓
Compare trade-offs


Examples:

Dynamic Array
→ std::vector

Linked List
→ std::list / std::forward_list

Stack
→ std::stack

Queue
→ std::queue

Deque
→ std::deque

Heap/Priority Queue
→ std::priority_queue

Hash Table
→ std::unordered_map / std::unordered_set

Ordered Tree-based container concept
→ std::map / std::set


Explain when the STL abstraction differs from the educational implementation.

Do not claim that a particular internal implementation is mandated by the C++ standard unless that is actually guaranteed.


# CURRICULUM


## 01 - Foundations

Cover:

- Big-O notation
- time complexity
- space complexity
- recursion basics
- pointers/references used in data structures
- stack vs heap
- contiguous vs non-contiguous storage
- cache locality
- ownership
- basic templates
- iterators


## 02 - Arrays

Cover:

- static arrays
- dynamic arrays
- insertion
- deletion
- traversal
- search
- resizing
- multidimensional arrays
- custom DynamicArray
- std::array
- std::vector


## 03 - Strings

Cover:

- character arrays
- null termination
- std::string
- traversal
- comparison
- substring concepts
- common string problems


## 04 - Linked Lists

Cover:

- singly linked list
- doubly linked list
- circular linked list
- insertion
- deletion
- search
- reversal
- middle node
- cycle detection
- std::forward_list
- std::list


## 05 - Stacks

Cover:

- stack concept
- array implementation
- linked-list implementation
- push
- pop
- top
- expression problems
- balanced parentheses
- std::stack


## 06 - Queues

Cover:

- queue
- array queue
- linked queue
- circular queue
- enqueue
- dequeue
- std::queue


## 07 - Deques

Cover:

- deque concept
- insertion at both ends
- deletion at both ends
- circular-buffer concepts
- std::deque


## 08 - Hash Tables

Cover:

- hashing
- hash functions
- buckets
- collisions
- separate chaining
- open addressing
- linear probing
- quadratic probing
- load factor
- rehashing
- std::unordered_map
- std::unordered_set


## 09 - Trees

Cover:

- tree terminology
- nodes
- root
- parent/child
- leaf
- depth
- height
- recursive representation
- DFS traversal
- BFS traversal


## 10 - Binary Search Trees

Cover:

- insertion
- search
- deletion
- minimum/maximum
- predecessor/successor
- inorder
- preorder
- postorder
- balanced vs unbalanced trees


## 11 - Heaps

Cover:

- binary heap
- min heap
- max heap
- array representation
- insertion
- heapify
- deletion
- heap construction
- heap sort


## 12 - Priority Queues

Cover:

- priority queue concept
- heap-backed implementation
- std::priority_queue
- custom comparators


## 13 - Tries

Cover:

- prefix trees
- insertion
- lookup
- deletion
- prefix search
- autocomplete concepts
- memory trade-offs


## 14 - Graphs

Cover:

- vertices
- edges
- directed graphs
- undirected graphs
- weighted graphs
- adjacency matrices
- adjacency lists
- BFS
- DFS
- cycle detection
- topological sorting
- shortest-path fundamentals


## 15 - Disjoint Set / Union-Find

Cover:

- sets
- find
- union
- path compression
- union by rank
- union by size
- cycle-detection applications


## 16 - STL Data Structures

Compare:

- std::array
- std::vector
- std::deque
- std::list
- std::forward_list
- std::stack
- std::queue
- std::priority_queue
- std::set
- std::map
- std::unordered_set
- std::unordered_map

Emphasize choosing the correct structure rather than memorizing containers.


## 17 - Advanced Data Structures

After prerequisites are completed, introduce:

- AVL Tree
- Red-Black Tree concepts
- Segment Tree
- Fenwick Tree / Binary Indexed Tree
- Sparse Table
- LRU Cache
- Bloom Filter concepts

Treat these as advanced topics and clearly identify their prerequisites.


# DOCUMENTATION REQUIREMENTS

Each topic's README.md should explain:

1. What is the data structure?
2. What problem does it solve?
3. Memory representation
4. Visual representation
5. Core operations
6. Implementation strategy
7. Time complexity
8. Space complexity
9. Edge cases
10. Common implementation mistakes
11. How to build
12. How to run
13. How to debug
14. STL equivalent
15. When to use it
16. When NOT to use it
17. Practical applications
18. Exercises


# EDGE CASES

Do not demonstrate only the happy path.

Test cases should include situations such as:

- empty structure
- one element
- duplicate values
- first element
- last element
- element not found
- capacity limit
- resize
- deleting root/head/tail
- copying
- moving
- destruction

Choose the applicable cases for each structure.


# TESTING

Provide simple automated tests where appropriate.

Tests should cover:

Normal case
Boundary case
Empty state
Single-element state
Invalid/request-not-found case
Copy/move semantics where relevant


Keep the learning demonstration separate from automated testing.


# PROBLEM-SOLVING SECTION

After learning a structure, include several problems.

Organize them approximately as:

Easy
Medium
Advanced


For example, after Linked Lists:

Easy:
- count nodes
- find a value
- find middle element

Medium:
- reverse linked list
- detect cycle
- remove duplicates

Advanced:
- find cycle starting point
- merge sorted lists
- clone structures containing additional links


Do not immediately provide the final solution.

First provide:
- problem
- example
- constraints
- hints
- expected complexity

Keep solutions in a separate solution file/section so the learner can attempt the problem independently.


# REAL-WORLD CONNECTION

Explain where structures appear in actual software.

Examples could include:

Queue
→ task scheduling/event processing

Heap
→ priority scheduling

Trie
→ prefix search/autocomplete

Graph
→ dependency/network relationships

Hash Table
→ indexing/caching/lookups

LRU Cache
→ bounded caching

Disjoint Set
→ dynamic connectivity/grouping


# BUILD SYSTEM

Use CMake.

Provide:

- root CMakeLists.txt
- topic-level CMakeLists.txt where useful
- Debug configuration guidance

Each major topic should be independently buildable and debuggable.


# CODE QUALITY

Prefer educational clarity over cleverness.

Code should be:

- compilable
- readable
- modern C++
- debugger friendly
- well named
- modular
- reasonably const-correct
- memory safe

Avoid:

- giant classes
- giant main.cpp
- macros except where justified
- unexplained metaprogramming
- excessive inheritance
- unnecessary design patterns
- compressed one-line implementations
- premature optimizations


# IMPORTANT LEARNING QUESTIONS

For every data structure, explicitly answer:

Why was this data structure created?

What problem does it solve better than another structure?

What does it look like in memory?

What is the cost of its major operations?

What is the most important trade-off?

Where is it useful?

Where is it a poor choice?

What does the C++ Standard Library provide for this problem?


# GENERATION STRATEGY

Do NOT generate the complete repository implementation at once.

Proceed incrementally.


## PHASE 1 - ARCHITECTURE

First generate:

1. Complete curriculum
2. Repository directory tree
3. Topic dependency map
4. CMake architecture
5. Naming conventions
6. Class/file conventions
7. Debugging strategy
8. Testing strategy


Show the learning dependency:

Foundations
   |
   +--> Arrays
   |      |
   |      +--> Stack
   |      +--> Queue
   |      +--> Heap
   |
   +--> Linked Lists
   |      |
   |      +--> Stack
   |      +--> Queue
   |
   +--> Trees
   |      |
   |      +--> BST
   |      +--> Heaps
   |      +--> Tries
   |
   +--> Hash Tables
   |
   +--> Graphs
          |
          +--> Disjoint Set


## PHASE 2 - FIRST TOPIC

After defining the architecture, completely implement:

01_Foundations

Provide:

- folder structure
- CMakeLists.txt
- main.cpp
- .h files
- .cpp files
- README.md content
- demonstrations
- tests
- build commands
- run commands
- debugger instructions
- expected output
- exercises


## PHASE 3 - SUBSEQUENT TOPICS

Continue one topic at a time.

For each new topic:

1. Explain prerequisites.
2. Explain the data structure conceptually.
3. Show its memory representation.
4. Implement it from scratch.
5. Demonstrate operations.
6. Demonstrate edge cases.
7. Analyze complexity.
8. Compare against STL.
9. Add tests.
10. Add debugging exercises.
11. Add coding problems.


# FINAL QUALITY CHECK

Before providing code, verify:

- Does it compile conceptually under C++17?
- Are headers and source files consistent?
- Is ownership clear?
- Is memory released correctly?
- Is undefined behavior avoided?
- Are boundary cases handled?
- Is each subtopic independently debuggable?
- Is main.cpp only an orchestrator?
- Are complexity claims justified?
- Is the STL comparison technically accurate?
- Can a developer understand the implementation by stepping through it?


# FIRST TASK

Start ONLY with PHASE 1.

Do not create hundreds of source files yet.

First provide the complete:

- curriculum
- repository architecture
- topic dependency map
- build architecture
- debugging approach
- testing approach

Then identify the first topic to implement and explain why it should come first.