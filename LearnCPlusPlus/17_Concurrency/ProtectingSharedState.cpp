#include "ProtectingSharedState.h"

#include <iostream>
#include <mutex>
#include <thread>

void ProtectingSharedStateExample::run()
{
    // Demonstrates protecting shared mutable state with a mutex.
    // Without synchronization, concurrent increments would be a data race.
    int counter{0};
    std::mutex counterMutex;
    const auto incrementManyTimes{[&counter, &counterMutex]() {
        for (int index{0}; index < 1000; ++index)
        {
            const std::lock_guard<std::mutex> lock{counterMutex};
            ++counter;
        }
    }};
    std::thread firstWorker{incrementManyTimes};
    std::thread secondWorker{incrementManyTimes};
    firstWorker.join();
    secondWorker.join();
    std::cout << "Counter after both workers: " << counter << '\n';

    // lock_guard unlocks even if control leaves its scope unexpectedly.
    // Keep critical sections short. Expected output is always 2000.
}