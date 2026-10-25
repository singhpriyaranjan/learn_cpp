# C++ Learning Project

This repository is a topic-by-topic set of small C++ programs. Each topic is
intended to have its own executable and `main.cpp`; that main only introduces
the topic and calls each example in order. Learning logic stays in the
subtopic's `.cpp` file so it is easy to set a breakpoint and rerun one topic.

The curriculum currently contains working examples in all 20 topic folders.
The attached `C++.pdf` is included in the workspace; its visible examples
include modern C++ material such as `constexpr`. The topic sequence follows
the requested curriculum, and examples use C++17 unless a lesson is explicitly
contrasting a later standard.

## Build and run

From the repository root, configure a Debug build and compile any topic target:

```powershell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug --target 01_Basics
```

Replace `01_Basics` with a target such as `10_SmartPointers` or
`17_Concurrency` to build another topic independently. To build every topic,
omit `--target`.

Run it with:

```powershell
./build/01_Basics/01_Basics.exe
```

With a multi-configuration generator such as Visual Studio, the executable is
usually under `build/01_Basics/Debug/01_Basics.exe`. CMake may use a different
layout for another generator; the build output reports the generated path.

Each topic can also be configured as an independent CMake project. For example,
run these commands from `10_SmartPointers`:

```powershell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug --target 10_SmartPointers
```

Open the repository root in VS Code, configure a CMake kit, select any topic
target, and start debugging it. Breakpoints can be set in each example's
`run()` method; topic `main.cpp` files execute lessons in order and print a
heading before each one. Keep a topic's executable selected to debug that topic
without stepping through the others.

## Implemented curriculum

1. `01_Basics`: variables, types, constants, operators, scope, conversions
2. `02_Functions`: parameters, return values, overloading
3. `03_ReferencesAndPointers`: aliases, addresses, nullable pointers
4. `04_ClassesAndObjects`: encapsulation, invariants, composition
5. `05_ConstructorsDestructors`: initialization, destruction, lifetime
6. `06_Inheritance`: is-a relationships, protected members
7. `07_Polymorphism`: virtual dispatch, abstract interfaces
8. `08_MemoryManagement`: automatic/dynamic storage, raw allocation
9. `09_RAII`: scoped resources, exception-safe cleanup
10. `10_SmartPointers`: unique, shared, and weak ownership
11. `11_OperatorOverloading`: arithmetic and equality operators
12. `12_Templates`: function and class templates
13. `13_STL`: vector, algorithms, map
14. `14_Lambdas`: lambda syntax, captures, algorithm predicates
15. `15_MoveSemantics`: move constructors, moving standard containers
16. `16_Exceptions`: standard and domain-specific exceptions
17. `17_Concurrency`: threads, joining, mutex-protected state
18. `18_ModernCpp`: C++17 optional values and structured bindings
19. `19_DesignPatterns`: Strategy and Factory
20. `20_DebuggingAndCommonMistakes`: assertions and checked access

Each folder has its own `main.cpp`, topic-level `CMakeLists.txt`, and paired
header/source files for its lessons. New topics can be added by following an
existing folder and registering it with `add_subdirectory(...)` in the root.