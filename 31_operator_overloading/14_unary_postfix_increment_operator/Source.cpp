#include "point.h"

int main()
{
	Point p1{ 10, 10 };
	std::cout << "p1: " << p1 << std::endl;

	++p1;
	std::cout << "p1 after increment: " << p1 << std::endl;

	for (size_t i{}; i < 20; ++i)
	{
		++p1;
		std::cout << "p1: " << p1 << std::endl;
	}

	std::cout << "postfix increment operator: " << p1++ << std::endl;
	std::cout << "incremented here: " << p1 << std::endl;


	return 0;
}

