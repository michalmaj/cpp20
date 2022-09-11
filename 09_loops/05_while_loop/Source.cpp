/*
 * while loop
 * Executes a statement repeatedly, until the value of condition becomes false. The test
 * takes place before each iteration.
 *
 * Syntax:
 * attr(optional) while ( condition ) statement
 */

#include <iostream>

int main()
{
	const size_t COUNT{ 10 };
	size_t i{ 0 }; // Iterator declaration

	while(i < COUNT)
	{
		std::cout << i << ": I love C++" << std::endl;
		++i; // Incrementation
	}
	std::cout << "Loop done!" << std::endl;

	return 0;
}