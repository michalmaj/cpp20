#include <iostream>

int main()
{
	// Increment/decrement pointer address manually
	int scores[10]{ 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	//scores++; // We can't modify where our scores pointing to

	int* p_score{ scores };

	std::cout << "Values in scores array (p_score pointer increment):" << std::endl;

	std::cout << "Address: " << p_score << " value: " << *(p_score) << std::endl;
	++p_score; // Moves forward by sizeof(int): 4 bytes
	std::cout << "Address: " << p_score << " value: " << *(p_score) << std::endl;
	++p_score; // Moves forward by sizeof(int): 4 bytes
	std::cout << "Address: " << p_score << " value: " << *(p_score) << std::endl;
	++p_score; // Moves forward by sizeof(int): 4 bytes
	std::cout << "Address: " << p_score << " value: " << *(p_score) << std::endl;
	++p_score; // Moves forward by sizeof(int): 4 bytes
	std::cout << "Address: " << p_score << " value: " << *(p_score) << std::endl;
	++p_score; // Moves forward by sizeof(int): 4 bytes
	std::cout << "Address: " << p_score << " value: " << *(p_score) << std::endl;
	++p_score; // Moves forward by sizeof(int): 4 bytes
	std::cout << "Address: " << p_score << " value: " << *(p_score) << std::endl;
	++p_score; // Moves forward by sizeof(int): 4 bytes
	std::cout << "Address: " << p_score << " value: " << *(p_score) << std::endl;
	++p_score; // Moves forward by sizeof(int): 4 bytes
	std::cout << "Address: " << p_score << " value: " << *(p_score) << std::endl;
	++p_score; // Moves forward by sizeof(int): 4 bytes
	std::cout << "Address: " << p_score << " value: " << *(p_score) << std::endl;
	++p_score; // Moves forward by sizeof(int): 4 bytes

	std::cout << "\n==========================================\n\n";

	std::cout << "Explicit addition of integer:" << std::endl;
	p_score = scores; // Reset the pointer to the start of the array
	std::cout << "scores[4]: " << *(p_score + 4) << std::endl; // Moves forward by 4 * sizeof(int)

	std::cout << "\n==========================================\n\n";

	// Can use loops to print these things out: easier version
	p_score = scores;

	std::cout << "Pointer arithmetic on p_score pointer and a for loop:" << std::endl;
	for (size_t i{ 0 }; i < std::size(scores); ++i)
		std::cout << "Value: " << *(p_score + i) << std::endl;

	std::cout << "\n==========================================\n\n";

	// Can also do arithmetic on the array name
	// just like any pointer
	p_score = scores;

	std::cout << "Pointer arithmetic on array name:" << std::endl;
	for (size_t i{ 0 }; i < std::size(scores); ++i)
		std::cout << "Value: " << *(scores + i) << std::endl;

	std::cout << "\n==========================================\n\n";

	// Can print elements in reverse order

	std::cout << "Elements in reverse order with decrementing pointer arithmetic:" << std::endl;
	for (size_t i{ std::size(scores) }; i > 0; --i)
		std::cout << "Value: " << *(scores + i - 1) << std::endl; // Here we do the -1 because
																  // scores is already pointing to the
																  // first element in the array

	std::cout << "\n==========================================\n\n";

	// Print in reverse order with operator-- on p_score
	std::cout << "Elements in reverse order, operator-- on the p_score pointer:" << std::endl;
	p_score = scores + std::size(scores) - 1;
	for (size_t i{ std::size(scores) }; i > 0; --i)
		std::cout << "Value: " << *(p_score--) << std::endl;

	std::cout << "\n==========================================\n\n";

	// CAn print the elements in reverse order with array index
	std::cout << "Elements in reverse order with array index notation:" << std::endl;
	for (size_t i{ std::size(scores) }; i > 0; --i)
		std::cout << "Values: " << scores[i - 1] << std::endl;

 
	return 0;
}