#include "StartingAThread.h"

#include <iostream>
#include <thread>

void StartingAThreadExample::run()
{
    // Demonstrates starting a worker thread and joining it.
    // A thread runs work concurrently; join waits until that work is finished.
    int result{0};
    std::thread worker{[&result]() {
        result = 6 * 7;
        std::cout << "Worker computed a value.\n";
    }};
    worker.join();
    std::cout << "Joined result: " << result << '\n';

    // The main thread reads result only after join, so this access is ordered.
    // Forgetting to join or detach a joinable thread terminates the program.
    // Expected output: worker message, then Joined result: 42.
}