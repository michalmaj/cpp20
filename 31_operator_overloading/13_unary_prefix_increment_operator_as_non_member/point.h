#pragma once

#include <iostream>


class Point
{
	friend std::ostream& operator<<(std::ostream& out, const Point& p);
	friend void operator++(Point& operand);

public:
	Point();
	Point(double x, double y);
	~Point() = default;


	double lenght() const;

private:
	double m_x;
	double m_y;
};

inline std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << "Point [ x : " << p.m_x << ", y : " << p.m_y << "]";
	return out;
}


//inline void operator++(Point& operand)
//{
//	++operand.m_x;
//	++operand.m_y;
//}