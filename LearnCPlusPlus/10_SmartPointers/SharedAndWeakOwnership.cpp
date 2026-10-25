#include "SharedAndWeakOwnership.h"

#include <iostream>
#include <memory>

void SharedAndWeakOwnershipExample::run()
{
    // Demonstrates shared ownership and a non-owning weak observer.
    // shared_ptr destroys the object when the final shared owner disappears.
    auto firstOwner{std::make_shared<int>(42)};
    std::weak_ptr<int> observer{firstOwner};
    {
        auto secondOwner{firstOwner};
        std::cout << "Owners: " << firstOwner.use_count() << '\n';
        if (const auto lockedValue{observer.lock()})
        {
            std::cout << "Observed value: " << *lockedValue << '\n';
        }
    }
    std::cout << "Owners after inner scope: " << firstOwner.use_count() << '\n';
    firstOwner.reset();
    std::cout << "Expired after final owner reset: " << std::boolalpha
              << observer.expired() << '\n';

    // weak_ptr does not keep the object alive; lock() safely tests/lends access.
    // Shared ownership has reference-counting cost and cycles can leak; use
    // unique_ptr by default. Expected owner counts: 2 then 1, then expired=true.
}