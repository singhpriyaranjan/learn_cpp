Create a well-structured C++ Learning Project that can be used to learn modern C++ concepts topic by topic through executable examples.
Use examples/topics from attached PDF

The project must prioritize:
1. Easy learning
2. Clean code organization
3. Easy debugging
4. Independent examples
5. Sequential execution of subtopics
6. Easy extension with new topics

PROJECT STRUCTURE
-----------------

Organize the project by C++ learning topics.

Each major topic shall have its own folder.

Example:

CppLearning/
│
├── 01_Basics/
│   ├── main.cpp
│   ├── Variables.cpp
│   ├── Variables.h
│   ├── DataTypes.cpp
│   ├── DataTypes.h
│   ├── References.cpp
│   └── References.h
│
├── 02_OOP/
│   ├── main.cpp
│   ├── ClassesObjects.cpp
│   ├── ClassesObjects.h
│   ├── Constructors.cpp
│   ├── Constructors.h
│   ├── Inheritance.cpp
│   ├── Inheritance.h
│   ├── Polymorphism.cpp
│   └── Polymorphism.h
│
├── 03_MemoryManagement/
│   ├── main.cpp
│   ├── StackHeap.cpp
│   ├── StackHeap.h
│   ├── RawPointers.cpp
│   ├── RawPointers.h
│   ├── SmartPointers.cpp
│   └── SmartPointers.h
│
└── ...

TOPIC ORGANIZATION
------------------

Each folder represents one major C++ topic.

Each subtopic shall have:
- A dedicated .h file
- A dedicated .cpp file
- A clearly named class
- A public method such as run(), demonstrate(), or execute()
- Small and focused example code
- Explanatory comments describing the C++ concept

Example:

class SmartPointersExample
{
public:
    void run();
};

The corresponding .cpp shall contain the actual learning example.

MAIN.CPP DESIGN
---------------

Every topic folder shall contain its own main.cpp.

The main.cpp acts as the entry point and learning navigator for that topic.

It shall instantiate and execute each subtopic sequentially.

Example:

int main()
{
    std::cout << "=== C++ Memory Management ===\n";

    StackHeapExample stackHeap;
    stackHeap.run();

    RawPointersExample rawPointers;
    rawPointers.run();

    SmartPointersExample smartPointers;
    smartPointers.run();

    return 0;
}

Do NOT put learning logic directly inside main.cpp.

main.cpp should only:
- display topic/subtopic information
- create example objects
- call their demonstration methods

This allows breakpoints to be placed easily on individual examples.

DEBUGGING REQUIREMENTS
----------------------

The project must be designed for easy debugging.

Therefore:

- Avoid putting multiple unrelated concepts into one function.
- Keep functions reasonably small.
- Use meaningful variable and function names.
- Avoid unnecessary templates/macros when demonstrating basic concepts.
- Avoid overly clever or compressed code.
- Prefer explicit intermediate variables so values can be inspected in the debugger.
- Make object lifetime visible where relevant.
- Print important object construction/destruction events where useful.
- Clearly identify each subtopic in console output.
- Each example should be independently debuggable.
- A learner should be able to put a breakpoint inside any run() method and understand the execution flow.

EXPLANATORY DOCUMENTATION
-------------------------

Each example source file shall explain:

1. What is being demonstrated?
2. Why does this C++ feature exist?
3. Basic syntax
4. How the example works
5. Important runtime behavior
6. Common mistakes
7. Good practices
8. Expected output

Use comments near the relevant code rather than providing only a large explanation at the beginning.

Where useful, explain:
- stack vs heap
- object lifetime
- scope
- ownership
- copy vs move
- references vs pointers
- const behavior
- compile-time vs runtime behavior

LEARNING STYLE
--------------

Examples should progress from simple to more advanced concepts.

For example:

Memory Management
   1. Stack objects
   2. Heap objects
   3. Raw pointers
   4. new/delete
   5. RAII
   6. std::unique_ptr
   7. std::shared_ptr
   8. std::weak_ptr
   9. Common memory-management mistakes

Do not introduce advanced concepts before the prerequisite concept has been demonstrated.

When one concept depends on another, mention the dependency.

MODERN C++
----------

Use modern C++ practices.

Target C++17 initially.

Where useful, mention how C++20 or newer versions improve or change the concept, but keep the main examples compatible with C++17 unless explicitly requested otherwise.

BUILD SYSTEM
------------

Use CMake.

Provide:
- Root CMakeLists.txt
- Topic-level CMakeLists.txt where appropriate
- Debug build support

The user should be able to build and debug individual learning topics independently.

CODE QUALITY
------------

Code must be:
- compilable
- simple
- readable
- educational
- debugger friendly
- free from unnecessary architectural complexity

Do not create production-level abstraction merely for demonstrating a language feature.

The objective is understanding C++, not demonstrating sophisticated software architecture.

INITIAL CURRICULUM
------------------

Create folders progressively for:

01_Basics
02_Functions
03_ReferencesAndPointers
04_ClassesAndObjects
05_ConstructorsDestructors
06_Inheritance
07_Polymorphism
08_MemoryManagement
09_RAII
10_SmartPointers
11_OperatorOverloading
12_Templates
13_STL
14_Lambdas
15_MoveSemantics
16_Exceptions
17_Concurrency
18_ModernCpp
19_DesignPatterns
20_DebuggingAndCommonMistakes

IMPORTANT
---------

Do not generate placeholder-only examples.

Every generated subtopic must contain a small working example that illustrates the actual C++ behavior.

Generate the project incrementally.

Start by:
1. Creating the overall folder structure.
2. Creating the root CMake configuration.
3. Fully implementing 01_Basics.
4. Explain how to build and debug it.
5. Then proceed topic by topic while maintaining exactly the same architectural pattern.