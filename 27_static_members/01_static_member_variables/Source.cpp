#include "point.h"

int main()
{
	// Print the point count in our program
	std::cout << "Point count: " << Point::m_point_count << std::endl; //0

	Point p1(10, 20);
	std::cout << "Point count: " << Point::m_point_count << std::endl; // 1

	Point points[]{ Point{1, 1}, Point(), Point{4} };
	std::cout << "Point count: " << Point::m_point_count << std::endl; // 4

	size_t result = p1.get_point_count();
	std::cout << "result: " << result << std::endl; // 5
	std::cout << "Point count: " << Point::m_point_count << std::endl; // 5

	return 0;
}