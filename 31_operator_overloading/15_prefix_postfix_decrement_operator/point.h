#pragma once

#include <iostream>


class Point
{
	friend std::ostream& operator<<(std::ostream& out, const Point& p);

public:
	Point();
	Point(double x, double y);
	~Point() = default;

	double lenght() const;

	// Prefix and postfix as member functions (comment these or non-member functions)
	Point operator++() // Prefix
	{
		++m_x;
		++m_y;

		return *this;
	}

	Point operator++(int) // Postfix
	{
		Point local_point{ *this };
		++(*this);
		return local_point;
	}

	// Prefix and postfix operator--
	Point operator--() // Prefix
	{
		--m_x;
		--m_y;
		return *this;
	}

	Point operator--(int)
	{
		Point local_point{ *this };
		--(*this);
		return local_point;
	}

private:
	double m_x;
	double m_y;
};

inline std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << "Point [ x : " << p.m_x << ", y : " << p.m_y << "]";
	return out;
}
