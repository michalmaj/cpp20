#pragma once

#include <iostream>

class Number;

class Point
{
	friend std::ostream& operator<<(std::ostream& out, const Point& p);

public:
	Point();
	Point(double x, double y);
	~Point() = default;

	void operator++()
	{
		++m_x;
		++m_y;
	}

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
