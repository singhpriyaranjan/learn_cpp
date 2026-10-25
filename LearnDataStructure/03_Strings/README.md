# 03 Strings

## Build and Run

From the repository root: configure with `cmake -S 03_Strings -B build/strings -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/strings --config Debug`, and test with `ctest --test-dir build/strings -C Debug --output-on-failure`. Run `strings` with the `strings` example argument; break at `isPalindrome`'s two-pointer comparison.

Text processing needs a sequence plus a clear length/termination contract. A C character array stores a null terminator; `std::string` owns its character storage and tracks length.

```text
std::string "level": [l][e][v][e][l]  length = 5
C string "safe":    [s][a][f][e][\0]
```

The example traverses from both ends for palindrome checking and reverses an owned string using the standard algorithm. Both operations take $O(n)$ time; palindrome checking uses $O(1)$ extra space, while the returned reversed copy uses $O(n)$. Empty and one-character input are valid. Do not read beyond `size()`, confuse `size()` with C-string terminator storage, or assume arbitrary bytes are Unicode characters.

Use `strings` or `strings --help`. Break at the two-pointer comparison and inspect the shrinking half-open interval. `std::string` is the practical STL type; `string_view` can provide a non-owning view when lifetime is guaranteed. Strings are central to parsing, protocols, and identifiers; avoid repeated concatenation in loops when it causes needless reallocations. Exercises: substring search, anagram check, and run-length encoding. Unicode normalization/grapheme processing and advanced substring algorithms remain exercises.

## PDF Alignment

The PDF includes string/character examples in its early array and recursion material and uses words as trie keys around pp. 287-301. This module expresses the relevant traversal and comparison patterns with `std::string`, making C++ ownership and null-terminated character-array differences explicit.