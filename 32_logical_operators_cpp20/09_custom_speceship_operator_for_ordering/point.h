#pragma once

#include <iostream>

class Point
{
	friend std::ostream& operator<< (std::ostream& out, const Point& p);

public:
	Point() = default;
	Point(double x_y) : Point(x_y, x_y) {}
	Point(double x, double y) : m_x{ x }, m_y{ y } {}

	bool operator==(const Point& other) const;
	std::partial_ordering operator<=>(const Point& other) const;

private:
	double length() const; // Calculate distance from origin to the point
private:
	double m_x{};
	double m_y{};
};

inline std::ostream& operator<< (std::ostream& out, const Point& p)
{
	out << "Point [ x : " << p.m_x << ", y : " << p.m_y <<
		" length : " << p.length() << "]";
	return out;
}