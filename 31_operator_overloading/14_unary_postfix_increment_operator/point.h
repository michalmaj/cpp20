#pragma once

#include <iostream>


class Point
{
	friend std::ostream& operator<<(std::ostream& out, const Point& p);
	friend Point operator++(Point& operand);

public:
	Point();
	Point(double x, double y);
	~Point() = default;
	
	double lenght() const;

	//// Prefix and postfix as member functions (comment these or non-member functions)
	//Point operator++() // Prefix
	//{
	//	++m_x;
	//	++m_y;

	//	return *this;
	//}

	//Point operator++(int) // Postfix
	//{
	//	Point local_point{ *this };
	//	++(*this);
	//	return local_point;
	//}

private:
	double m_x;
	double m_y;
};

inline std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << "Point [ x : " << p.m_x << ", y : " << p.m_y << "]";
	return out;
}


// Prefix and postfix as non-member functions (comment these or member functions)
inline Point operator++(Point& operand) // Prefix
{
	++operand.m_x;
	++operand.m_y;

	return operand;
}

inline Point operator++(Point& operand, int) // Postfix
{
	Point local_point{ operand };
	++(operand);
	return local_point;
}