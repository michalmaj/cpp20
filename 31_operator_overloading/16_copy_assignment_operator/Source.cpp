#include <iostream>
#include "point.h"

int main()
{
	Point p1{ 10, 10, 10 };
	Point p2{ 20, 20, 20 };

	std::cout << "p1: " << p1 << std::endl;
	std::cout << "p2: " << p2 << std::endl;

	std::cout << "\n===================================\n\n";

	// Assignment
	p2 = p1;

	std::cout << "p1: " << p1 << std::endl;
	std::cout << "p2: " << p2 << std::endl;

	std::cout << "\n===================================\n\n";

	// Change data
	p1.set_data(55);

	std::cout << "p1: " << p1 << std::endl;
	std::cout << "p2: " << p2 << std::endl;


	std::cout << "\n===================================\n\n";


	Point p3(30, 30, 30);
	Point p4(p3);
	std::cout << p4 << std::endl;

	std::cout << "\n===================================\n\n";

	Point p5 = p3; // It will be copy constructor not an assignment operator.
	p3.set_data(77);
	std::cout << p5 << std::endl;

	std::cout << "\n===================================\n\n";

	Point p77{ 3, 3, 3 };

	//p1 = p2 = p77;
	// Instead of using assignment above, we can also call
	p1.operator=(p2.operator=(p77));
	std::cout << "p1: " << p1 << std::endl;
	std::cout << "p2: " << p2 << std::endl;

	return 0;
}