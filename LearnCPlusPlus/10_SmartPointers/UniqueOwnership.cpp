#include "UniqueOwnership.h"

#include <iostream>
#include <memory>
#include <utility>

class Document
{
public:
    explicit Document(int pageCount) : pageCount_{pageCount}
    {
        std::cout << "Document created\n";
    }
    ~Document() { std::cout << "Document destroyed\n"; }
    int pageCount() const { return pageCount_; }

private:
    int pageCount_;
};

void UniqueOwnershipExample::run()
{
    // Demonstrates exclusive ownership. unique_ptr deletes its object when the
    // owner leaves scope, so there is exactly one owner.
    // Use make_unique to create it; unique_ptr cannot be copied, only moved.
    auto document{std::make_unique<Document>(12)};
    std::cout << "Pages: " << document->pageCount() << '\n';
    auto transferredOwner{std::move(document)};
    std::cout << "Ownership transferred: " << std::boolalpha << (document == nullptr)
              << "; pages: " << transferredOwner->pageCount() << '\n';

    // The moved-from pointer is empty; the new owner still controls lifetime.
    // Avoid releasing ownership manually unless interfacing with a C API.
    // Expected: created; pages 12; transfer true; destroyed at scope exit.
}