#pragma once

#include <iostream>

class Point
{
public:
	Point(double x, double y);
	Point(double xy_coord);
	Point();
	Point(const Point& p);
	~Point();

	double length() const;

	static size_t get_point_count()
	{
		return m_point_count;
	}

	static void print_info(const Point& p)
	{
		std::cout << "Point: [x: " << p.m_x << ", y: " << p.m_y << "]\n";
	}

private:
	double m_x;
	double m_y;
	static size_t m_point_count;
};

