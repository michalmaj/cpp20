/*
 * First rule is that: "All variables in an expression should be of the same type".
 * If a compiler notices that we have a different types, it's going to insert an
 * implicit conversion on our types. For example:
 * int + double - double * int
 * all int's will be converted to doubles.
 * Second rule "Smaller types will be converted to bigger type in memory sizes".
 * Implicit conversions are done by the compiler without our involvement.
 *
 * There is an exception to this rule. When we do an assignment operation it is
 * possible to cause implicit narrowing conversion.
 */

#include <iostream>


int main()
{
	double price{ 45.6 };
	int units{ 10 };

	auto total_price = price * units;

	std::cout << "Total price: " << total_price << std::endl;
	// It will be double - 8 bytes
	std::cout << "sizeof total_price: " << sizeof(total_price)<< std::endl;

	int x;
	double y{ 45.44 };
	// This operation (assignment) will cause an implicit narrowing conversion.
	// y will be converted to int before assignment.
	x = y;
	std::cout << "The value of x: " << x << std::endl;
	// It will be int - 4 bytes
	std::cout << "sizeof x: " << sizeof(x) << std::endl;

	return 0;
}