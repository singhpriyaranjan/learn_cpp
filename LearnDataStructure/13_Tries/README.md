# 13 Tries

## Build and Run

From the repository root: configure with `cmake -S 13_Tries -B build/tries -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/tries --config Debug`, and test with `ctest --test-dir build/tries -C Debug --output-on-failure`. Run `tries prefix`; break when a missing child node is allocated.

A trie shares prefixes across keys, making prefix lookup proportional to key length rather than the number of stored words.

```text
root -> t -> r -> e -> e*     * marks a complete word
                  i -> e*
```

Insert and exact lookup are $O(L)$ for word length $L$; memory is proportional to allocated nodes times alphabet width in this simple 26-way layout. `unique_ptr` children own descendants. Empty words are supported; characters outside lowercase `a`-`z` throw. Break at child allocation and distinguish an existing prefix from a terminal word. A fixed-width child array is fast but wasteful for sparse nodes; maps or compressed edges trade access cost and complexity. Tries power dictionaries and autocomplete. Run `tries prefix`; deletion/autocomplete are exercises, as are Unicode alphabets and memory-efficient radix tries.

## PDF Alignment

The PDF's trie-node, word insertion, and lookup examples appear around pp. 287-301. This C++17 version keeps the prefix-tree idea while using explicit child ownership and documenting the fixed lowercase alphabet's memory trade-off.