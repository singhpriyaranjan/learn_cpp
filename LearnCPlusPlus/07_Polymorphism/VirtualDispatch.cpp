#include "VirtualDispatch.h"

#include <iostream>

class Animal
{
public:
    virtual ~Animal() = default;
    virtual void speak() const { std::cout << "Animal sound\n"; }
};

class Dog : public Animal
{
public:
    void speak() const override { std::cout << "Woof\n"; }
};

class Cat : public Animal
{
public:
    void speak() const override { std::cout << "Meow\n"; }
};

void VirtualDispatchExample::run()
{
    // Demonstrates runtime polymorphism: a base reference calls the derived
    // override selected from the actual object type.
    // `virtual` enables dynamic dispatch; `override` checks intent at compile time.
    Dog dog;
    Cat cat;
    const Animal& firstAnimal{dog};
    const Animal& secondAnimal{cat};
    firstAnimal.speak();
    secondAnimal.speak();

    // The virtual base destructor is required when deleting derived objects
    // through base pointers. Without virtual, calls can select the base method.
    // Expected output: Woof, then Meow.
}