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
		// static variable is not associated with any object so i can be modified
		// even in a methods marked as const
		++m_point_count;

		return m_point_count;
	}

	void initialize_pointer(double x, double y)
	{
		p_m_point4 = new Point(x, y);
	}

	void print_info() const
	{
		std::cout << "Point  [ &m_x : " << &m_x << ", &m_y : " << &m_y << "]" << std::endl;
	}

public:
	//Point m_point1; // Incomplete type compiler error
	//const Point m_point2; // Incomplete type compiler error
	//static inline Point m_point3{}; // Incomplete type compiler error

	// But we have 2 options
	Point* p_m_point4; // Works

	static const Point m_point4;
	static Point m_point5;

private:
	double m_x;
	double m_y;

	inline static size_t m_point_count{0};
};

