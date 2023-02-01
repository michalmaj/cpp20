#include <iostream>
#include <ranges>
#include <vector>

int main()
{
	//// Generate an infinite sequence of numbers
	//auto infinite_view = std::views::iota(1); // Stores the computation

	//// Numbers are generated lazily, on the fly, as we need them in each iteration
	//for (auto i : infinite_view)
	//	std::cout << i << std::endl;

	// Generate sequence of items [n, m)
	auto bounded_view = std::views::iota(10, 20); // from 10 to 19
	for(auto i : bounded_view)
		std::cout << i << std::endl;

	std::cout << "\n=====================================\n\n";

	// Get n number of elements from std::view::iota
	auto limited_view = std::views::iota(1) | std::views::take(20);
	for (auto i : limited_view)
		std::cout << i << std::endl;

	std::cout << "\n=====================================\n\n";

	auto data_view = std::views::take(std::views::iota(10), 5);
	for (auto i : data_view)
		std::cout << i << std::endl;

	std::cout << "\n=====================================\n\n";

	for(auto i : std::views::take(std::views::iota(1), 20))
		std::cout << i << std::endl;

	std::cout << "\n=====================================\n\n";

	for(auto i : std::views::iota(1) | std::views::take(10))
		std::cout << i << std::endl;

	return 0;
}