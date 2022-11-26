#pragma once

#include <iostream>


class Point
{
	friend std::ostream& operator<<(std::ostream& out, const Point& p);

public:
	Point();
	Point(double x, double y, int data);
	Point(const Point& p); // Copy constructor
	Point& operator=(const Point& right_operand);
	~Point();

	double lenght() const;

	void set_data(int data);


private:
	double m_x;
	double m_y;
	int* p_data;
};

inline std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << "Point [ x : " << p.m_x << ", y : " << p.m_y << ", data: "
		<< *p.p_data << "]";
	return out;
}
