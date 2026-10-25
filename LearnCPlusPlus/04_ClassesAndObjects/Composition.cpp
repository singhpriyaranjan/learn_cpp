#include "Composition.h"

#include <iostream>
#include <string>

class Battery
{
public:
    explicit Battery(int capacityPercent) : capacityPercent_{capacityPercent} {}
    int capacityPercent() const { return capacityPercent_; }

private:
    int capacityPercent_;
};

class PortableSpeaker
{
public:
    explicit PortableSpeaker(int batteryCapacity) : battery_{batteryCapacity} {}

    void play(const std::string& song) const
    {
        std::cout << "Playing " << song << " with " << battery_.capacityPercent()
                  << "% battery.\n";
    }

private:
    Battery battery_;
};

void CompositionExample::run()
{
    // Demonstrates composition: a speaker contains a Battery member.
    // Use a has-a relationship when one object is built from another.
    // A member is initialized in the containing object's constructor list.
    PortableSpeaker speaker{80};
    speaker.play("A short tune");

    // Battery lifetime follows speaker lifetime without manual allocation.
    // Avoid inheritance for a has-a relationship.
    // Expected output: Playing A short tune with 80% battery.
}