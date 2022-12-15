#pragma once

#include <iostream>
#include <string_view>

class Shape
{
public:
	Shape();
	Shape(std::string_view description);
	~Shape() = default;

public:
	void draw() const
	{
		std::cout << "Shape::draw() called for: " << m_description << std::endl;
	}

private:
	void func() const
	{
		std::cout << "Shape::func() called for: " << m_description << std::endl;
	}

protected:
	std::string m_description;
};

