#include "point.h"

#include <cmath>

bool Point::operator==(const Point& other) const
{
	return (this->length() == other.length());
}

double Point::length() const
{
	return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}