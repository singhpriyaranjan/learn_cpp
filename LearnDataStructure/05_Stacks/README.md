# 05 Stacks

## Build and Run

From the repository root: configure with `cmake -S 05_Stacks -B build/stacks -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/stacks --config Debug`, and test with `ctest --test-dir build/stacks -C Debug --output-on-failure`. Run `stacks parentheses`; break at the unmatched-closing check.

A stack solves last-in, first-out workflows: the newest item is the first removed. The implementation stores values in a vector, making this an array-backed stack; a linked alternative can trade locality for node allocation.

```text
top -> [3]  pop removes only this end
       [2]
       [1]
```

Push and pop are amortized $O(1)$ with vector growth (worst-case push $O(n)$ during reallocation); storage is $O(n)$. Empty pop throws `underflow_error`. Parenthesis checking uses one stack entry per unmatched opening bracket, so time and worst-case space are $O(n)$. The sample intentionally focuses on round parentheses; extending to multiple bracket types requires storing bracket characters.

Run `stacks parentheses`; break at the closing-bracket check and inspect stack size. `std::stack` is an adaptor, commonly backed by a sequence container, and exposes only stack operations. Stacks appear in parsing, undo histories, and depth-first traversal; they are a poor fit when oldest-first access is required. Exercises: evaluate postfix expressions, support `top`, and implement a linked stack. The linked version and full expression grammar are not implemented here.

## PDF Alignment

The PDF's stack-operation and expression examples (approximately pp. 122-135, with additional stack/deque comparisons around pp. 143-149) motivate the LIFO and bracket-checking demonstrations. This is a C++17 translation using `std::vector` and explicit underflow handling, not a port of Java collection code.