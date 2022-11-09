#pragma once

#include <iostream>

class Point
{
public:
	// Constructors
	Point(double x, double y);
	Point(double xy_coord); // Point constructor
	Point(); // default constructor
	Point(const Point& point); // copy constructor
	~Point(); // destructor

	// Methods
	double length() const; // Function to calculate distance from the point(0, 0)

	size_t get_point_count() const
	{
		// static variable is not associated with any object so it can be modified
		// even in a methods marked as const
		//++m_point_count;

		return m_point_count;
	}

	void print_info() const
	{
		std::cout << "Point  [ &m_x : " << &m_x << ", &m_y : " << &m_y << "]" << std::endl;
	}

private:
	double m_x;
	double m_y;

	inline static size_t m_point_count{0}; // Since C++17 it is possible to mark static
										   // variable as inline and initialize in same line
};

