#pragma once

#include <iostream>

class Number;

class Point
{
	friend std::ostream& operator<<(std::ostream& out, const Point& p);
	friend Point operator+=(Point& left, const Point& right);
	friend Point operator-=(Point& left, const Point& right);
	friend Point operator+(const Point& left, const Point& right);
	friend Point operator-(const Point& left, const Point& right);

public:
	Point();
	Point(double x, double y);
	//explicit Point(const Number& n);
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

inline Point operator+=(Point& left, const Point& right)
{
	return { left.m_x += right.m_x, left.m_y += right.m_y };
}

inline Point operator-=(Point& left, const Point& right)
{
	return { left.m_x -= right.m_x, left.m_y -= right.m_y };
}

inline Point operator+(const Point& left, const Point& right)
{
	//return { left.m_x + right.m_x, left.m_y + right.m_y };
	Point p{ left };
	return p += right;
}
inline Point operator-(const Point& left, const Point& right)
{
	//return { left.m_x - right.m_x, left.m_y - right.m_y };
	Point p{ left };
	return p -= right;
}