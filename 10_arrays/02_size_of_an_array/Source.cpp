/*
 * We can check size of array by sizeof trick and since C++17 by std::size
 *
 * sizeof trick:
 * divide sizeof(arr) by sizeof first element:
 * sizeof(arr) / sizeof(arr[0])
 *
 * std::size()
 * returns the size of a container or array
 */

#include <iostream>

int main()
{
	int scores[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	// Uncomment one: sizeof or std::size

	// sizeof trick
	std::cout << "sizeof(scores): " << sizeof(scores) << std::endl;
	std::cout << "sizeof(scores[0]): " << sizeof(scores[0]) << std::endl;
	size_t count{ sizeof(scores) / sizeof(scores[0]) };

	//// Usage of std::size
	//size_t count{ std::size(scores)}; // Added in C++17

	for (size_t i{ 0 }; i < count; ++i)
		std::cout << "scores[" << i << "]: " << scores[i] << std::endl;


	// Instead of searching for size of array, we can simply use range-based for loop
	// If you need an information about index, we can add initializer, and update
	// it inside our loop
	for(size_t idx{0}; const auto& value : scores)
	{
		std::cout << "Index: " << idx++ << ": ";
		std::cout << "value: " << value << std::endl;
	}


	return 0;
}