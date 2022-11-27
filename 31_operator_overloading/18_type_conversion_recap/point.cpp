#include "point.h"
#include "number.h"

Point::Point(double x, double y) : m_x(x), m_y(y)
{
}

//Point::Point(const Number& n)
//{
//	std::cout << "Point Constructor from Number called..." << std::endl;
//	m_x = m_y = n.get_wrapped_int();
//}

void Point::operator=(const Number& n)
{
	std::cout << "Point copy assignment operator from Number called..." << std::endl;
	m_x = m_y = n.get_wrapped_int();
}


Point::Point(const Point& p)
{
	std::cout << "Copy constructor called to copy point " << std::endl;
	if(this != &p)
	{
		m_x = p.m_x;
		m_y = p.m_y;
	}
}


