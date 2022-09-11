/*
 * do-while loop
 * Executes a statement repeatedly, until the value of expression becomes false. The test
 * takes place after each iteration.
 *
 * Syntax:
 * attr(optional) do statement while ( expression ) ;		
 */

#include <iostream>

int main()
{
	const int COUNT{ 10 };
	size_t i{ 0 };

	do
	{
		std::cout << i << ": I love C++" << std::endl;
		++i; // Incrementation
	} while (i < COUNT);

	return 0;
}