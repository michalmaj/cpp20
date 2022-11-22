#pragma once

#include <iostream>

class Point
{
	friend Point operator+(const Point& p1, const Point& p2);
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {}
	~Point() = default;


	void print_info() const
	{
		std::cout << "Point [x: " << m_x << ", y: " << m_y << "]" << std::endl;
	}

	double length() const;



private:
	double m_x{};
	double m_y{};
};

inline Point operator+(const Point& p1, const Point& p2)
{
	return { p1.m_x + p2.m_x, p1.m_y + p2.m_y };
}