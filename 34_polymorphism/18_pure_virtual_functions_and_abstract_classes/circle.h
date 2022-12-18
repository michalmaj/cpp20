#pragma once

#include "shape.h"
#include <numbers>

class Circle : public Shape
{
public:
	Circle() = default;
	Circle(double radius, std::string_view description);
	virtual ~Circle() = default;

	virtual double perimeter() const override
	{
		return (2 * std::numbers::pi * m_radius);
	}

	virtual double surface() const override
	{
		return (std::numbers::pi * m_radius * m_radius);
	}

private:
	double m_radius{ 0.0 };
};

