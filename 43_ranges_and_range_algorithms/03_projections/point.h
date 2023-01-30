#pragma once

#include <iostream>
#include <compare>

class Point
{
	friend std::ostream& operator<<(std::ostream& out, const Point& p);

public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y){}

	// Operators
	bool operator==(const Point& other) const;
	std::partial_ordering operator<=>(const Point& right) const;

	// Getters
	double get_x() const { return m_x; }
	double get_y() const { return m_y; }

private:
	double m_x{};
	double m_y{};

	double length() const; // Function to calculate distance from the point(0, 0)
};

inline std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << "Point [ x : " << p.m_x << ", y : " << p.m_y <<
		" , length : " << p.length() << " ]";
	return out;
}

