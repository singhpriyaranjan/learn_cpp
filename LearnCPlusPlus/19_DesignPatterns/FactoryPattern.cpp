#include "FactoryPattern.h"

#include <iostream>
#include <memory>
#include <string>

class Notification
{
public:
    virtual ~Notification() = default;
    virtual std::string channel() const = 0;
};

class EmailNotification : public Notification
{
public:
    std::string channel() const override { return "email"; }
};

class SmsNotification : public Notification
{
public:
    std::string channel() const override { return "SMS"; }
};

std::unique_ptr<Notification> makeNotification(bool useEmail)
{
    if (useEmail)
    {
        return std::make_unique<EmailNotification>();
    }
    return std::make_unique<SmsNotification>();
}

void FactoryPatternExample::run()
{
    // Demonstrates a small factory function that chooses a concrete type and
    // returns it through an owning interface pointer.
    const auto notification{makeNotification(false)};
    std::cout << "Created notification channel: " << notification->channel() << '\n';

    // unique_ptr makes ownership explicit and the virtual destructor permits
    // safe deletion through the base. Use a factory only when construction
    // choice is useful to centralize. Expected output: SMS.
}