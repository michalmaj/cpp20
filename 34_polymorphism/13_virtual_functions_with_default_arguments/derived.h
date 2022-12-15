#pragma once

#include "base.h"

class Derived : public Base
{
public:
	Derived() = default;
	~Derived() = default;

	virtual double add(double a = 10, double b = 10) const override
	{
		std::cout << "Derived::add() called" << std::endl;
		return (a + b + 2);
	}
};

