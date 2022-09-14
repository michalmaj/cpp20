/*
 * Arrays are used to store multiple values in a single variable, instead of declaring
 * separate variables for each value.
 *
 * To declare an array, define the variable type, specify the name of the array followed by
 * square brackets and specify the number of elements it should store
 */

#include <iostream>


int main()
{

	// Declare an array of ints
	int scores[10]; // Junk data

	// Read data
	std::cout << "scores[0]: " << scores[0] << std::endl;
	std::cout << "scores[1]: " << scores[1] << std::endl;

	std::cout << "\n========================================\n\n";

	// Read with a loop
	for(size_t i{0}; i < 10; ++i)
	{
		std::cout << "scores[" << i << "]: " << scores[i] << std::endl;
	}

	std::cout << "\n========================================\n\n";

	//Write data
	scores[0] = 20;
	scores[1] = 21;
	scores[2] = 22;
	for (size_t i{ 0 }; i < 10; ++i)
	{
		std::cout << "scores[" << i << "]: " << scores[i] << std::endl;
	}

	std::cout << "\n========================================\n\n";

	// Write data in a loop
	for (size_t i{ 0 }; i < 10; ++i)
	{
		scores[i] = i * 10;
	}

	for (size_t i{ 0 }; i < 10; ++i)
	{
		std::cout << "scores[" << i << "]: " << scores[i] << std::endl;
	}

	std::cout << "\n========================================\n\n";

	// Declare and initialize at the same time
	std::cout << "Declare and initialize at the same time:" << std::endl;

	double salaries[5]{ 12.7, 7.5, 13.2, 8.1, 9.3 };
	for (size_t i{ 0 }; i < 5; ++i)
	{
		std::cout << "salary[" << i << "]: " << salaries[i] << std::endl;
	}

	std::cout << "\n========================================\n\n";

	// If you don't initialize all the elemnts, those you leave out are initialized to 0
	int families[5]{ 12, 7, 5 };
	for (size_t i{ 0 }; i < 5; ++i)
	{
		std::cout << "families[" << i << "]: " << families[i] << std::endl;
	}

	std::cout << "\n========================================\n\n";

	// Omit the size of the array at declaration, compiler deduces size
	int class_sizes[]{ 10, 12, 15, 11, 18, 17 };

	// Let's print this with a range-based for loop
	for (const auto& value : class_sizes)
		std::cout << "value: " << value << std::endl;

	std::cout << "\n========================================\n\n";

	// Can't modify const array 
	const int birds[]{ 10, 12, 15, 11, 18, 17, 23, 56 };
	//birds[2] = 4; // Compiler Error: you cannot assign to a variable that is constant

	std::cout << "\n========================================\n\n";

	// Sum up elements in array, store result in variable sum
	int marks[]{ 2, 5, 8, 2, 5, 6, 9 };
	int sum{ 0 };

	for (const auto& element : marks)
		sum += element;
	std::cout << "Our sum: " << sum << std::endl;

	return 0;
}