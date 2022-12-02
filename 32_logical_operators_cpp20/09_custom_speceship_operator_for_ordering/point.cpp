#include "point.h"

#include <cmath>

bool Point::operator==(const Point& other) const
{
	return (this->length() == other.length());
}

std::partial_ordering Point::operator<=>(const Point& other) const
{
	if (length() > other.length())
		return std::partial_ordering::greater;
	else if (length() == other.length())
		return std::partial_ordering::equivalent;
	else if (length() < other.length())
		return std::partial_ordering::less;
	else
		return std::partial_ordering::unordered;
}


double Point::length() const
{
	return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}