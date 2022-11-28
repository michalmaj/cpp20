#pragma once

#include <iostream>

class Point
{
	friend std::ostream& operator<<(std::ostream& out, const Point& p);

	// Operators as non-members
	friend bool operator>(const Point& left, const Point& right);
	friend bool operator<(const Point& left, const Point& right);
	friend bool operator>=(const Point& left, const Point& right);
	friend bool operator<=(const Point& left, const Point& right);
	friend bool operator==(const Point& left, const Point& right);
	friend bool operator!=(const Point& left, const Point& right);

public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {}
	~Point() = default;

	double length() const;

	//// Operators as members
	//bool operator>(const Point& other) const;
	//bool operator<(const Point& other) const;
	//bool operator>=(const Point& other) const;
	//bool operator<=(const Point& other) const;
	//bool operator==(const Point& other) const;
	//bool operator!=(const Point& other) const;

private:
	double m_x{};
	double m_y{};
};

inline std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << "Point [x: " << p.m_x << ", y: " << p.m_y << ", length: " << p.length() << "]";
	return out;
}