#include <iostream>
import math;
import print;


int main()
{
	auto result = add(10, 20);
	std::cout << "result: " << result << std::endl;

	greet("Michael");

	print_name_length("Michael");

	result = dist(10, 20);
	std::cout << "result: " << result << std::endl;

	Point point1(22, 44);
	std::cout << "point1: " << point1 << std::endl;

	return 0;
}