#pragma once

#include "shape.h"

class Ellipse : public Shape
{
public:
	Ellipse();
	Ellipse(double x_radius, double y_radius, std::string_view description);
	~Ellipse();

	virtual int get_count() const override
	{
		return m_count;
	}

	inline static int m_count{ 0 };

private:
	double m_x_radius;
	double m_y_radius;
};

