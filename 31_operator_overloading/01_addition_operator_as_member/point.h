#pragma once

#include <iostream>

class Point
{
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y){}
	~Point() = default;

	// Member function
	//Point operator+(const Point& p) const
	//{
	//	return {m_x + p.m_x, m_y + p.m_y};
	//}

	Point operator+(const Point& p) const;

	void print_info() const
	{
		std::cout << "Point [x: " << m_x << ", y: " << m_y << "]" << std::endl;
	}

	double length() const;

	

private:
	double m_x{};
	double m_y{};
};

