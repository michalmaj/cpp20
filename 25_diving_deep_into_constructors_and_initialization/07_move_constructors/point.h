#pragma once

#include <iostream>

class Point
{
private:
	double* x{};
	double* y{};

	void invalidate()
	{
		x = nullptr;
		y = nullptr;
	}

public:
	Point(double x_param, double y_param);
	~Point();

	// Copy constructor
	Point(const Point& source_point);

	// Move constructor
	Point(Point&& source_point);

	// Setters
	void set_x(double x) { *(this->x) = x; }
	void set_y(double y) { *(this->y) = y; }

	// Getters
	double* get_x() const { return x; }
	double* get_y() const { return y; }

	//Utilities
	void print_info()const {
		std::cout << "Point [ x : " << *x << ", y: " << (*y) << "]" << std::endl;
	}
};

