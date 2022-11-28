#include "point.h"

#include <cmath>


double Point::length() const
{
	return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2));
}

//// Operators as members
//bool Point::operator>(const Point& other) const
//{
//	return (this->length() > other.length());
//}
//
//bool Point::operator<(const Point& other) const
//{
//	return (this->length() < other.length());
//}
//
//bool Point::operator>=(const Point& other) const
//{
//	return (this->length() >= other.length());
//}
//
//bool Point::operator<=(const Point& other) const
//{
//	return (this->length() <= other.length());
//}
//
//bool Point::operator==(const Point& other) const
//{
//	return (this->length() == other.length());
//}
//
//bool Point::operator!=(const Point& other) const
//{
//	return (this->length() != other.length());
//}

// Operators as non-members
bool operator>(const Point& left, const Point& right)
{
	return (left.length() > right.length());
}

bool operator<(const Point& left, const Point& right)
{
	return (left.length() < right.length());
}

bool operator>=(const Point& left, const Point& right)
{
	return (left.length() >= right.length());
}

bool operator<=(const Point& left, const Point& right)
{
	return (left.length() <= right.length());
}

bool operator==(const Point& left, const Point& right)
{
	return (left.length() == right.length());
}

bool operator!=(const Point& left, const Point& right)
{
	return (left.length() != right.length());
}