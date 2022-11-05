#include <iostream>
#include "square.h"

bool compare(const Square& square1, const Square& square2)
{
	return (square1.surface() > square2.surface()) ? true : false;
}

int main()
{
	Square s1{ 100.0 };
	Square s2{ 20.0 };

	std::cout << std::boolalpha;
	std::cout << "s1 > s2: " << compare(s1, s2) << std::endl;

	//// Implicit conversion
	//std::cout << "s1 > 45.9: " << compare(s1, 45.9) << std::endl; // Will work as long as constructor can be use to
	//															  // convert from double to Square and it not marked
	//															  // as explicit

	return 0;
}