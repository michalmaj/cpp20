#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int n{ 24 };

	std::vector<int> collection{ 14, 24, 7, 8, 98, 11 };

	auto result = std::find(std::begin(collection), std::end(collection), n);

	if (result != collection.end())
		std::cout << "collection contains: " << n << " at index: " << result - collection.begin() << std::endl;
	else
		std::cout << "collection doesn't contain: " << n << std::endl;

	std::cout << "\n==================================================\n\n";

	auto odd = [](int x)
	{
		return (x % 2 != 0) ? true : false;
	};

	auto odd_n_position = std::find_if(std::begin(collection), std::end(collection), odd);

	if (odd_n_position != std::end(collection))
		std::cout << "collection contains at least one odd number: " << *odd_n_position <<
		" at index: " << odd_n_position - std::begin(collection) << std::endl;



	return 0;
}