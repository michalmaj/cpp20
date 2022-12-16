#pragma once

#include <iostream>
#include <string_view>


class Animal
{
public:
	Animal() = default;
	Animal(std::string_view description);
	virtual ~Animal();

	virtual void breathe() const
	{
		std::cout << "Animal::breathe called for: " << m_description << std::endl;
	}

protected:
	std::string m_description;
};

