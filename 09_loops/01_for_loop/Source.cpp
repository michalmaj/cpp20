/*
 * for loop
 * Executes init-statement once, then executes statement and iteration-expression repeatedly,
 * until the value of condition becomes false. The test takes place before each iteration.
 *
 * Syntax:
 * attr(optional) for ( declaration-or-expression(optional) ; declaration-or-expression(optional) ; expression(optional) )
 */
#include <iostream>

int main()
{
	//// Print I love c++ 10 times - the BAD way
	//std::cout << "I love C++" << std::endl;
	//std::cout << "I love C++" << std::endl;
	//std::cout << "I love C++" << std::endl;
	//std::cout << "I love C++" << std::endl;
	//std::cout << "I love C++" << std::endl;
	//std::cout << "I love C++" << std::endl;
	//std::cout << "I love C++" << std::endl;
	//std::cout << "I love C++" << std::endl;
	//std::cout << "I love C++" << std::endl;
	//std::cout << "I love C++" << std::endl;

	// for loop: the GOOD way
	for(unsigned int i{0}; i < 10; ++i)
	{
		std::cout << i << ": " << "I love C++" << std::endl;
	}
	std::cout << "Loop done!" << std::endl;

	std::cout << "\n================================\n\n";

	// Use size_t: a representation of some unsigned int for positive numbers [sizes]
	for(size_t i{0}; i < 10; ++i)
	{
		std::cout << i << ": I love C++" << std::endl;
	}
	std::cout << "Loop done!" << std::endl;

	std::cout << "\n================================\n\n";

	// sizeof(size_t)
	std::cout << "sizeof(size_t): " << sizeof(size_t) << std::endl;

	std::cout << "\n================================\n\n";

	// Scope of for loop, our variable i is visible only in for loop scope
	for (size_t i{ 0 }; i < 10; ++i)
	{
		std::cout << i << ": I love C++" << std::endl;
	}
	std::cout << "Loop done!" << std::endl;
	//std::cout << "i: " << i << std::endl; // i is not in this scope

	std::cout << "\n================================\n\n";

	// Iterator declared outside the loop
	size_t i{ 0 }; // Iterator define outside
	for ( ; i < 10; ++i)
	{
		std::cout << i << ": I love C++" << std::endl;
	}
	std::cout << "Loop done!" << std::endl;
	std::cout << "i: " << i << std::endl; // this time i is visible, declared before for loop


	std::cout << "\n================================\n\n";

	// Don't hard code values
	const size_t COUNT{ 10 };
	for (size_t i{ 0 }; i < COUNT; ++i)
	{
		std::cout << i << ": I love C++" << std::endl;
	}
	std::cout << "Loop done!" << std::endl;


	return 0;
}