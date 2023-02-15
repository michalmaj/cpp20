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

	std::vector<int> data{ 1, 2, 3, 4, 5 };

	for (const auto& d : data)
		std::cout << "value: " << d << std::endl;

	return 0;
}