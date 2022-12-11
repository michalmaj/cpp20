#pragma once

#include "shape.h"

class Oval : public Shape
{
public:
	Oval() = default;
	Oval(double x_radius, double y_radius, std::string_view description);
	~Oval() = default;

	virtual void draw() const override
	{
		std::cout << "Oval::draw() called. Drawing " << m_description <<
			" with m_x_radius: " << m_x_radius << " and m_y_radius " <<
			m_y_radius << std::endl;
	}

	// If we want to have a draw method with one parameter we need to overload that function as well 
	virtual void draw(int color_depth) const override
	{
		std::cout << "Oval::Drawing with color depth: " << color_depth << std::endl;
	}

	// This method is created in Oval class, this method won't participate in Shape polymorphism
	virtual void draw(int color_depth, std::string_view color) const
	{
		std::cout << "Drawing with color depth: " << color_depth <<
			" and color: " << color << std::endl;
	}

public:
	double get_x_rad() const
	{
		return m_x_radius;
	}

	double get_y_rad() const
	{
		return m_y_radius;
	}

private:
	double m_x_radius{ 0.0 };
	double m_y_radius{ 0.0 };
};

