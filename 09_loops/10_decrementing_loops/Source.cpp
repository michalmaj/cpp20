#include <iostream>
#include <string>
#include <ranges> // for experienced users, it lets us use ranges
				  // The ranges library is an extension and generalization of the algorithms
				  // and iterator libraries that makes them more powerful by making them
				  // composable and less error-prone.

int main()
{

	// For loops
	const size_t COUNT{ 5 };

	std::cout << "Increment for loop:" << std::endl;
	for(size_t i{}; i < COUNT; ++i)
	{
		std::cout << "i: " << i << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Decrement for loop:" << std::endl;
	for(size_t i{COUNT}; i > 0; --i)
	{
		std::cout << "i: " << i << std::endl;
	}

	// Look out for underflow for size_t
	std::cout << std::endl;
	std::cout << "size_t underflow:" << std::endl;
	std::cout << "size_t -1" << (size_t(0) - 1) << std::endl;

	std::cout << std::endl;
	std::cout << "Decrement for loop with std::string::npos guard:" << std::endl;
	// std::string::npos is a static member constant value with the greatest possible value
	// for an element of type size_t.
	for (size_t i{ COUNT }; i != std::string::npos; --i)
	{
		std::cout << "i: " << i << std::endl;
	}

	// While loop
	std::cout << std::endl;
	std::cout << "Increment while loop:" << std::endl;

	size_t i{ 0 };
	while(i < COUNT)
	{
		std::cout << "i: " << i << std::endl;
		++i;
	}

	std::cout << std::endl;
	std::cout << "Decrement while loop:" << std::endl;

	i = COUNT;
	while (i > 0)
	{
		std::cout << "i: " << i << std::endl;
		--i;
	}

	// Do while loop
	std::cout << std::endl;
	std::cout << "Increment do while loop:" << std::endl;

	i = 0;
	do
	{
		std::cout << "i: " << i << std::endl;
		++i;
	} while (i < COUNT);

	std::cout << std::endl;
	std::cout << "Decrement do while loop:" << std::endl;

	i = COUNT;
	do
	{
		std::cout << "i: " << i << std::endl;
		--i;
	} while (i > 0);




	// Without extra effort range based for loop can't be made to run in reverse order.
	// But with extra effort using std::ranges::views::revers we can run in reverse order.
	// Example of range based for loop from last element to first using ranges.
	int arr[]{ 1, 2, 3, 4, 5 }; // C-style array
	std::cout << std::endl;
	std::cout << "Decrement range-based for loop:" << std::endl;
	// A range adaptor that represents a view of underlying view with reversed order.
	for (int idx{}; const auto & e : std::ranges::views::reverse(arr))
		std::cout << idx++ << ": " << e << std::endl;;
	std::cout << std::endl;

	return 0;
}