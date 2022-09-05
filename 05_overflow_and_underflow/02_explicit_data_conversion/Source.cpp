/*
 * The explicit data conversion are actively initiated by the developer.
 *
 * There are two ways to cast C-style and C++.
 * Example for C-style, cast a variable named var of a double type to an int type:
 * (int)var
 * C++ cast in other hand is preferable method: static_cast<int>(var)
 * This method is easy to search in code, in addition is checked by compiler. If the types
 * are not compatible, we will get a compiler error.
 */

#include <iostream>


int main()
{
	// Implicit conversion first add then convert
	double x{ 12.5 };
	double y{ 34.6 };

	int sum = x + y;

	std::cout << "The sum is: " << sum << std::endl;

	// We can do an explicit cast, cast then sum.
	// So first we cast x and y to integers, then sum.
	sum = static_cast<int>(x) + static_cast<int>(y);
	std::cout << "The sum is: " << sum << std::endl;

	// In other hand we can first sum up, then cast to int
	sum = static_cast<int>(x + y);
	std::cout << "The sum is: " << sum << std::endl;

	// Old cast in C-style
	double PI{ 3.14 };
	int int_pi = (int)PI;
	std::cout << "int pi: " << int_pi << std::endl;



	return 0;
}