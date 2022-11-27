#pragma once

#include <iostream>

class Number;

class Point
{
	friend std::ostream& operator<<(std::ostream& out, const Point& point);

public:
	Point() = default;
	Point(double x, double y);
	Point(const Point& p); // copy constructor
	//Point(const Number& n); // constructor for Number class
	~Point() = default;

	// copy assignment operator
	Point& operator=(const Point& right_operand)
	{
		std::cout << "Copy assignment called" << std::endl;
		if(this != &right_operand)
		{
			m_x = right_operand.m_x;
			m_y = right_operand.m_y;
		}
		return *this;
	}

	// Copy assignment for Number class
	void operator=(const Number& n);

private:
	double m_x;
	double m_y;
};

inline std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "Point [ x : " << point.m_x << ", y : " << point.m_y << " ]";
	return os;
}
