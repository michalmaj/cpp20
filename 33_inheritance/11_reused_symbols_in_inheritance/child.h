#pragma once

#include "parent.h"

class Child : public Parent
{
public:
	Child() = default;
	Child(int member_var) :m_member_var(member_var) {}
	~Child() = default;

	void print_var() const
	{
		std::cout << "The value in child is: " << m_member_var << std::endl;
	}

	void show_values() const
	{
		std::cout << "The value in child is: " << m_member_var << std::endl;
		std::cout << "The value in parent is: " << Parent::m_member_var << std::endl;
	}

private:
	int m_member_var{ 1000 };
};

