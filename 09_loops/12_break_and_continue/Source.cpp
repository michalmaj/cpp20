/*
 * break statement:
 * Causes the enclosing for, range-for, while or do-while loop or switch statement to
 * terminate.Used when it is otherwise awkward to terminate the loop using the condition
 * expression and conditional statements.
 *
 * continue statement:
 * Causes the remaining portion of the enclosing for, range-for, while or do-while loop body
 * to be skipped. Used when it is otherwise awkward to ignore the remaining portion of the
 * loop using conditional statements.
 */

#include <iostream>

int main()
{
	// break and continue (for loop)
	const size_t COUNT{ 20 };
	for(size_t i{0}; i < COUNT; ++i)
	{
		// Skip when i is equal to 5 
		if(i == 5)
			continue;
		// End loop when i is equal to 11 
		if (i == 11)
			break;
		std::cout << "i: " << i << std::endl;
	}
	std::cout << "Loop done!" << std::endl;

	std::cout << "\n===============================================\n" << std::endl;

	// break and continue (while loop)
	size_t i{ 0 };
	while(i < COUNT)
	{
		// Skip when i is equal to 5 
		if (i == 5)
		{
			++i; // We need to increment because i will be 5 forever
			continue;
		}
		// End loop when i is equal to 11 
		if (i == 11)
			break;
		std::cout << "i: " << i << std::endl;
		++i;
	}
	std::cout << "Loop done!" << std::endl;


	std::cout << "\n===============================================\n" << std::endl;

	// break and continue (do-while loop)
	i = 0;
	do
	{
		// Skip when i is equal to 5 
		if (i == 5)
		{
			++i; // We need to increment because i will be 5 forever
			continue;
		}
		// End loop when i is equal to 11 
		if (i == 11)
			break;
		std::cout << "i: " << i << std::endl;
		++i;
	} while (i < COUNT);
	std::cout << "Loop done!" << std::endl;

	return 0;
}