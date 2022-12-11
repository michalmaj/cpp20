#pragma once

#include <iostream>
#include <string_view>

class Shape
{
public:
	Shape() = default;
	Shape(std::string_view description);
	~Shape() = default;

	virtual void draw() const
	{
		std::cout << "Shape::draw() called. Drawing " << m_description << std::endl;
	}

protected:
	std::string m_description{};
};

