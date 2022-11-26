#include "point.h"

#include <cmath>

Point::Point() : m_x(0), m_y(0), p_data(nullptr) {}
Point::Point(double x, double y, int data) : m_x(x), m_y(y), p_data(new int{data}) {}
Point::Point(const Point& p)
{
	std::cout << "Copy constructor called to copy point " << p << std::endl;
	if(this != &p)
	{
		delete p_data;
		p_data = new int(*(p.p_data));

		m_x = p.m_x;
		m_y = p.m_y;
	}
}

Point& Point::operator=(const Point& right_operand)
{
	std::cout << "Copy assignment operator called\n";
	if(this != &right_operand)
	{
		delete p_data;
		p_data = new int(*(right_operand.p_data));

		m_x = right_operand.m_x;
		m_y = right_operand.m_y;
	}

	return *this;
}


Point::~Point()
{
	std::cout << "Delete: " << *p_data << std::endl;
	delete p_data;
}



void Point::set_data(int data)
{
	*p_data = data;
}

double Point::lenght() const
{
	return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}
