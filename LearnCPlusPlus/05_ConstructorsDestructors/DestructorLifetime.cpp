#include "DestructorLifetime.h"

#include <iostream>
#include <string>
#include <utility>

class TracedObject
{
public:
    explicit TracedObject(std::string name) : name_{std::move(name)}
    {
        std::cout << "Construct " << name_ << '\n';
    }

    ~TracedObject()
    {
        std::cout << "Destroy " << name_ << '\n';
    }

private:
    std::string name_;
};

void DestructorLifetimeExample::run()
{
    // Demonstrates deterministic destruction at the end of each scope.
    // Destructors let objects release resources automatically.
    TracedObject outer{"outer"};
    {
        TracedObject inner{"inner"};
        std::cout << "Inside nested scope.\n";
    }
    std::cout << "Back in outer scope.\n";

    // Locals are destroyed in reverse construction order. Never call a
    // destructor manually for an ordinary automatic object.
    // Expected: inner is destroyed before outer.
}