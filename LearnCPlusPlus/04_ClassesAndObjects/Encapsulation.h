#ifndef CPP_LEARNING_ENCAPSULATION_H
#define CPP_LEARNING_ENCAPSULATION_H

#include <string>

class BankAccount
{
public:
    explicit BankAccount(std::string owner, int openingBalance);
    bool deposit(int amount);
    int balance() const;
    const std::string& owner() const;

private:
    std::string owner_;
    int balance_;
};

class EncapsulationExample
{
public:
    void run();
};

#endif