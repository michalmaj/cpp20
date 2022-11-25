#include "point.h"

int main()
{
	Point p1{ 10, 10 };

	std::cout << "p1--: " << p1-- << std::endl; // (10, 10)
	std::cout << "p1: " << p1 << std::endl; // (9, 9)

	std::cout << "--p1: " << --p1 << std::endl; // (8, 8)


	return 0;
}

