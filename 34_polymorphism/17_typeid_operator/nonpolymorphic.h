#pragma once

#include <iostream>

class StaticBase
{
public:
	void do_something() const
	{
		std::cout << "StaticBase::do_something() called" << std::endl;
	}
};

class StaticDerived : public StaticBase
{
public:
	void do_something() const
	{
		std::cout << "StaticDerived::do_something() called" << std::endl;
	}
};