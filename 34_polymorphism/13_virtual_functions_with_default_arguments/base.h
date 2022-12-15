#pragma once

#include <iostream>

class Base
{
public:
	Base() = default;
	~Base() = default;

	virtual double add(double a=5, double b=5) const
	{
		std::cout << "Base::add() called" << std::endl;
		return (a + b + 1);
	}
};

