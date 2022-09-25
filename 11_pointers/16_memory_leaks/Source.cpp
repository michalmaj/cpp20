/*
 * Memory leaks
 * It occurs when we loose access to memory that is dynamically  allocated
 */

#include <iostream>


int main()
{
	// Change pointing adders before releasing 
	int* p_number{ new int{67} }; // Points to some address

	int number2{ 55 }; // Lives at address2, stack variable

	// Should delete and reset here p_number, before point to number
	p_number = &number2; // Now p_number points to address2 , but address1 is still in use by 
                         // our program. But our program has lost access to that memory location.
						 //Memory has been leaked.

	// Double allocation
	int* p_number1{ new int{55} };

	// Should delete and reset here
	p_number1 = new int{ 44 }; // Memory with int{55} leaked.

	delete p_number1;
	p_number1 = nullptr;


	// Nested scopes with dynamically allocated memory
	{
		int* p_number2{ new int{57} };
	}
	// Memory with int{57} leaked

	return 0;
}