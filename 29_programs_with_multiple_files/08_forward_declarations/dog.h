#pragma once

#include <iostream>


class Dog
{
public:
	Dog() = default;
	Dog(const std::string& name);
	~Dog() = default;

	void print_info() const
	{
		std::cout << "Dog [name: " << name << "]" << std::endl;
	}

private:
	std::string name{};
};

