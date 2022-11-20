#pragma once

#include <iostream>
#include <string_view>

class Dog
{
public:
	explicit Dog(std::string_view name);
	Dog() = default;
	~Dog();

	void print_dog() const
	{
		std::cout << "Printing dog: " << dog_name << std::endl;
	}

	std::string get_name() const
	{
		return dog_name;
	}

	void set_dog_name(std::string_view name)
	{
		dog_name = name;
	}

private:
	std::string dog_name{ "Puffy" };
};

