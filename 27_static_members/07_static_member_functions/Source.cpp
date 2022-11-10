#include <iostream>
#include "point.h"

int main()
{

	std::cout << "Point count: " << Point::get_point_count() << std::endl; // 0

	Point p1{6, 7};
	std::cout << "Point count: " << Point::get_point_count() << std::endl; // 1

	p1.print_info(p1);

	Point::print_info(p1);

	return 0;
}