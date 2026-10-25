#include "CapturesAndAlgorithms.h"

#include <algorithm>
#include <iostream>
#include <vector>

void CapturesAndAlgorithmsExample::run()
{
    // Demonstrates captures and a predicate passed to std::count_if.
    // A capture makes selected local values available to the lambda body.
    const int passingScore{70};
    const std::vector<int> scores{68, 75, 92, 54, 81};
    const int passingCount{static_cast<int>(std::count_if(
        scores.begin(), scores.end(), [passingScore](int score) {
            return score >= passingScore;
        }))};
    std::cout << "Scores at least " << passingScore << ": " << passingCount << '\n';

    // Capture by value keeps a snapshot; capture by reference can observe or
    // mutate the original and must not outlive it. Expected output: 3.
}