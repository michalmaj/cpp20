#include "point.h"

#include <cmath>

Point::Point() : m_x(0), m_y(0) {}
Point::Point(double x, double y) : m_x(x), m_y(y) {}



double Point::lenght() const
{
	return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

void operator++(Point& operand)
{
	++operand.m_x;
	++operand.m_y;
}
