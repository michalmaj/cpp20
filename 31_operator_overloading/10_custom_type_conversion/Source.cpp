#include <iostream>
#include <typeinfo>
#include "number.h"
#include "point.h"

double sum(double a, double b)
{
	return a + b;
}

void use_point(const Point& p)
{
	std::cout << "Printing the point from use_point function: " << p << std::endl;
}

int main()
{
	Number n1{ 22 };
	Number n2{ 10 };
	std::cout << n1 << std::endl;
	std::cout << (n1 + Number{ 33 }) << std::endl;

	auto result = sum(static_cast<double>(n1), static_cast<double>(n2));
	std::cout << "result: " << result << ", type: " << typeid(result).name() << std::endl;
	use_point(static_cast<Point>(n1));

	return 0;
}