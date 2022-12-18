#pragma once

#include <iostream>

class DynamicBase
{
public:
	virtual void do_something() const
	{
		std::cout << "DynamicBase::do_something() called" << std::endl;
	}

	virtual ~DynamicBase() = default;
};

class DynamicDerived : public DynamicBase
{
public:
	virtual void do_something() const override
	{
		std::cout << "DynamicDerived::do_something() called" << std::endl;
	}

	virtual ~DynamicDerived() = default;
};