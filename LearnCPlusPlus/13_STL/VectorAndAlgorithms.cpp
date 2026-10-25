#include "VectorAndAlgorithms.h"

#include <algorithm>
#include <iostream>
#include <vector>

void VectorAndAlgorithmsExample::run()
{
    // Demonstrates std::vector and standard algorithms. Containers manage
    // storage; algorithms express common operations without manual loops.
    // vector grows as needed; sort reorders its elements in place.
    std::vector<int> scores{72, 95, 81, 64};
    scores.push_back(88);
    std::sort(scores.begin(), scores.end());

    std::cout << "Sorted scores:";
    for (const int score : scores)
    {
        std::cout << ' ' << score;
    }
    std::cout << '\n';

    // Iterators define the algorithm's range [first, last). Avoid indexing
    // outside vector size; use at() when checked access is desired.
    // Expected output: 64 72 81 88 95.
}