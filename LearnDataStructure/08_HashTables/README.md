# 08 Hash Tables

## Build and Run

From the repository root: configure with `cmake -S 08_HashTables -B build/hash_tables -DCMAKE_BUILD_TYPE=Debug`, build with `cmake --build build/hash_tables --config Debug`, and test with `ctest --test-dir build/hash_tables -C Debug --output-on-failure`. Run `hash_tables chaining`; break at the bucket scan and inspect colliding entries.

Hash tables map keys to buckets for fast expected lookup. The small table uses separate chaining: keys sharing a bucket are retained together, so collisions do not overwrite one another.

```text
hash(key) % 5 -> bucket
bucket 1: (1,10) -> (6,60)   (collision chain)
```

Lookup/insert are expected $O(1)$ with a well-distributed hash and controlled load factor, but worst-case $O(n)$ when keys collide. Space is $O(m+n)$ for $m$ buckets and $n$ entries. Updating an existing key replaces its value; missing lookup returns `nullopt`. The demonstration hash is intentionally simple and handles the shown non-minimum integers; robust generic hashing, negative minimum overflow, resizing, and adversarial keys need production-quality hash policy. `std::unordered_map`/`unordered_set` provide standard abstractions without mandating a particular bucket strategy. Run `hash_tables chaining`; inspect collisions at `put`. Useful for indexes/caches; poor when deterministic ordering is required. Exercises: implement linear/quadratic probing, load factor, and rehash.

## PDF Alignment

The PDF uses Java `HashMap` in frequency/map examples and trie discussions (for example, around pp. 74-84 and 287-301), but those usages do not teach bucket layout or collision resolution. This module adds a from-scratch chained table in C++ and explicitly studies collisions, load factor, and rehashing as course material.