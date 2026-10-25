#include "ExceptionSafeScope.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class TrackedBuffer
{
public:
    explicit TrackedBuffer(std::size_t size) : bytes_(size)
    {
        std::cout << "Allocate " << bytes_.size() << " bytes\n";
    }

    ~TrackedBuffer() { std::cout << "Release buffer\n"; }
    std::size_t size() const { return bytes_.size(); }

private:
    std::vector<char> bytes_;
};

void ExceptionSafeScopeExample::run()
{
    // Demonstrates cleanup during exception unwinding. RAII protects resources
    // even when normal execution is interrupted by an exception.
    try
    {
        TrackedBuffer buffer{16};
        std::cout << "Working with " << buffer.size() << " bytes\n";
        throw std::runtime_error{"demonstration error"};
    }
    catch (const std::runtime_error& error)
    {
        std::cout << "Caught: " << error.what() << '\n';
    }

    // buffer is destroyed before catch begins. Use standard containers and
    // RAII wrappers rather than relying on manually paired cleanup statements.
    // Expected: allocate, work, release, then catch message.
}