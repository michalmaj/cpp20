#include "boxcontainer.h"
#include <ranges>
#include <algorithm>

template <typename T>
void print(const BoxContainer<T>& c)
{
	for (const auto& e : c)
		std::cout << e << " ";
	std::cout << std::endl;
}

int main()
{
	BoxContainer<int> vi{ 5, 1, 7, 2, 5, 3, 7, 9, 6 };

	const BoxContainer<int> copy(vi);

	std::cout << "data:" << std::endl;
	for (auto it = copy.begin(); it != copy.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << std::endl;

	// Print through a function
	print(copy);

	// Attempt to sort copy
	//std::ranges::sort(copy); // Compiler error: can't sort a const collection

	std::ranges::sort(vi);
	print(vi);

	auto result = std::ranges::find(copy, 7);
	std::cout << result - copy.begin() << std::endl;




	return 0;
}