#include "point.h"

int main()
{
	Point p1(10.0, 15.0);
	p1.print_info();

	// Create a copy from a temporary
	Point p3(std::move(Point(20.5, 5.8)));
	p3.print_info();

	return 0;
}