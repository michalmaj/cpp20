#include "point.h"

int main()
{
	Point p1(10.0, 15.0);
	p1.print_info();

	//Point p2; // Default constructor deleted

	//Point p3(p1); // Copy constructor deleted

	//Point p4(std::move(Point(10.0, 15.0))); // Move constructor deleted

	return 0;
}