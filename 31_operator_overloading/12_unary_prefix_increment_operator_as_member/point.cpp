#include "point.h"

#include <cmath>

Point::Point() : m_x(0), m_y(0) {}
Point::Point(double x, double y) : m_x(x), m_y(y) {}
//Point::Point(const Number& n)
//: Point(static_cast<double>(n.get_wrapped_int()), static_cast<double>(n.get_wrapped_int()))
//{}


double Point::lenght() const
{
	return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}