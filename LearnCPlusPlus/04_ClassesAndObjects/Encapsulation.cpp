#include "Encapsulation.h"

#include <iostream>
#include <utility>

BankAccount::BankAccount(std::string owner, int openingBalance)
    : owner_{std::move(owner)}, balance_{openingBalance}
{
}

bool BankAccount::deposit(int amount)
{
    if (amount <= 0)
    {
        return false;
    }
    balance_ += amount;
    return true;
}

int BankAccount::balance() const
{
    return balance_;
}

const std::string& BankAccount::owner() const
{
    return owner_;
}

void EncapsulationExample::run()
{
    // Demonstrates private state and checked public actions. Encapsulation
    // protects invariants by making changes pass through the class interface.
    // The constructor establishes state; deposit rejects invalid input.
    BankAccount account{"Avery", 100};
    const bool accepted{account.deposit(25)};
    const bool rejected{account.deposit(-10)};
    std::cout << account.owner() << " balance: $" << account.balance() << '\n';
    std::cout << "Positive accepted: " << std::boolalpha << accepted
              << "; negative accepted: " << rejected << '\n';

    // Callers cannot write balance_ directly. Avoid public mutable fields when
    // values must remain valid. Expected final balance: $125; true; false.
}