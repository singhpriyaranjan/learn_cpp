#include "PublicInheritance.h"

#include <iostream>
#include <string>
#include <utility>

class Person
{
public:
    explicit Person(std::string name) : name_{std::move(name)} {}
    const std::string& name() const { return name_; }

private:
    std::string name_;
};

class Student : public Person
{
public:
    Student(std::string name, int studentId)
        : Person{std::move(name)}, studentId_{studentId}
    {
    }

    void introduce() const
    {
        std::cout << name() << " is a student; ID " << studentId_ << ".\n";
    }

private:
    int studentId_;
};

void PublicInheritanceExample::run()
{
    // Demonstrates public inheritance for an is-a relationship: Student is
    // also Person. The derived constructor initializes its base subobject first.
    // Syntax: class Derived : public Base { ... }.
    Student student{"Kai", 42};
    student.introduce();

    // Base private state is accessed through its public interface. Inherit to
    // model substitutability, not merely to reuse implementation.
    // Expected output: Kai is a student; ID 42.
}