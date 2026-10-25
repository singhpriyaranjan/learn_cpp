#include "ScopedResource.h"

#include <iostream>

class ScopedConnection
{
public:
    explicit ScopedConnection(int connectionId) : connectionId_{connectionId}
    {
        std::cout << "Open connection " << connectionId_ << '\n';
    }

    ~ScopedConnection()
    {
        std::cout << "Close connection " << connectionId_ << '\n';
    }

    void send(const char* message) const
    {
        std::cout << "Send: " << message << '\n';
    }

private:
    int connectionId_;
};

void ScopedResourceExample::run()
{
    // Demonstrates RAII: acquire a resource in construction and release it in
    // destruction. This ties resource lifetime to a reliable lexical scope.
    // Constructing the guard opens the connection; leaving run closes it.
    ScopedConnection connection{7};
    connection.send("hello");

    // Destructors run on normal scope exit and during stack unwinding. Avoid
    // separate cleanup paths that can be skipped by early returns.
    // Expected: open, send, then close connection 7.
}