# 01 Foundations

Foundations supplies the vocabulary needed to reason about every later container: growth rates, recursion, storage, lifetime, ownership, templates, and iterators. It answers why one pass over $n$ values is $O(n)$, why recursive calls consume stack space, and why an owning smart pointer is different from a non-owning pointer.

## Representation and Implementation

```text
automatic lifetime                 dynamic lifetime owned by unique_ptr
stack frame                         heap allocation
+-------------+                    +-------------+
| stackValue  | <--- observer       | ownedValue  |
+-------------+                    +-------------+
                                      unique_ptr releases it at scope exit
```

`factorial` is a small recursive example with a base case and rejects negative input. `sumRange` is a header-defined iterator template and accepts compatible iterator pairs. The memory example uses a raw pointer only as a non-owning observer; `std::unique_ptr` owns and releases its allocation. No owning raw pointer is copied, so Rule-of-Zero ownership is preferred over handwritten special members.

## Operations and Complexity

| Example | Time | Extra space | Why |
| --- | --- | --- | --- |
| Sum a range | $O(n)$ | $O(1)$ | Each element is visited once. |
| Factorial | $O(n)$ | $O(n)$ | One call is made per descending value and remains on the call stack. |
| Read an iterator value | $O(1)$ | $O(1)$ | Dereference cost is constant for the vector iterators used here. |

The example values avoid integer overflow; production factorial needs a range/overflow policy. Recursion depth, null/dangling observers, and use-after-lifetime are important debugging hazards. A vector stores elements contiguously, unlike a linked structure; contiguous traversal typically uses cache lines more effectively. C++ does not promise that every object is physically on a particular hardware stack or heap, but automatic/dynamic storage duration describes the language-level lifetime model.

## Build, Run, Debug

From the repository root:

```powershell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
ctest --test-dir build -C Debug --output-on-failure
```

Run `build\01_Foundations\Debug\foundations.exe --help` with Visual Studio generators, or `build/01_Foundations/foundations --help` with single-config generators. Pass `recursion`, `memory`, `iterators`, or `complexity` to focus execution. Break at `factorial`'s base case and recursive return; inspect `observer` as an alias and `ownedValue` as the owner; inspect iterator values and the loop invariant in `sumRange`.

## STL Connection, Trade-offs, Applications

Iterators and templates are the vocabulary behind generic standard algorithms and containers. Use standard ownership types by default; raw pointers remain useful for explicit non-owning relationships and low-level structure lessons. Complexity describes scaling, not constant factors, allocation costs, locality, or invalidation rules.

Applications include performance review, API design, resource management, and diagnosing lifetime bugs in any data structure. Exercises: compare linear and nested loops; trace `factorial(4)` by call frame; identify invalidation after vector growth; write an iterator-based maximum; explain the difference between an observer and an owner.

## PDF Alignment

The PDF's recursion and recurrence-analysis notes (approximately pp. 27-44) inform the `factorial` call-stack trace and complexity discussion. This guide extends those ideas with C++ storage duration, explicit ownership, templates, and iterators; its examples and wording are original C++17 material.