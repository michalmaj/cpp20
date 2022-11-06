#include "point.h"

Point::Point(double x_param, double y_param)
	: x(new double(x_param)),
	y(new double(y_param))
{}

Point::~Point()
{
	delete x;
	delete y;
}

//Point::Point(const Point& source_point)
//	: Point(*(source_point.get_x()), *(source_point.get_y()))
//{
//	std::cout << "Copy constructor\n";
//}
//
//
//// Move constructor
////Point::Point(Point&& source_point)
////	: x(source_point.get_x()),
////	  y(source_point.get_y())
////{
////	source_point.invalidate();
////	std::cout << "Move constructor\n";
////}
//
//// We can also use a stealing methods
//Point::Point(Point&& source_point)
//	: x(source_point.steal_x()),
//	y(source_point.steal_y())
//{
//	std::cout << "Move constructor\n";
//}