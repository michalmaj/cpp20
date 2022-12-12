#pragma once

#include "animal.h"
class Bird : public Animal
{
public:
    Bird() = default;
    Bird(std::string_view wing_color, std::string_view description);

    virtual ~Bird();

    virtual void fly() const {
        std::cout << "Bird::fly() called for bird : " << m_description << std::endl;
    }

private:
    std::string m_wing_color;
};