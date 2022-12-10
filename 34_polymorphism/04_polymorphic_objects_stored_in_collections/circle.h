#pragma once

#include "oval.h"

class Circle : public Oval
{
public:
	Circle() = default;
	Circle(double radius, std::string_view description);
	~Circle() = default;

	virtual void draw() const
	{
		std::cout << "Circle::draw() called. Drawing " << m_description <<
			" with radius: " << get_x_rad() << std::endl;
	}
};

