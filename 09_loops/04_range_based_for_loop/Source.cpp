/*
 * Range-based for loop
 * Executes a for loop over a range.
 * Used as a more readable equivalent to the traditional for loop operating over a range of
 * values, such as all elements in a container.
 *
 * Syntax:
 * attr(optional) for ( init-statement(optional) range-declaration : range-expression )
 */

#include <iostream>

int main()
{
	int bag_of_values[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //collection of integers

	// normal for loop
	for(size_t i{0}; i < 10; ++i)
	{
		std::cout << "value: " << bag_of_values[i] << std::endl;
	}

	std::cout << "\n=======================\n\n";

	// Range-based for loop
	for(int value : bag_of_values)
	{
		// value holds a copy of the current iteration in the whole bag
		std::cout << "value: " << value << std::endl;
	}

	std::cout << "\n=======================\n\n";

	// Specify the collection in place
	for(int value : { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 })
	{
		// value holds a copy of the current iteration in the whole bag
		std::cout << "value: " << value << std::endl;
	}

	std::cout << "\n=======================\n\n";

	// Auto type deduction
	for (auto value : { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 })
	{
		// value holds a copy of the current iteration in the whole bag
		std::cout << "value: " << value << std::endl;
	}


	return 0;
}