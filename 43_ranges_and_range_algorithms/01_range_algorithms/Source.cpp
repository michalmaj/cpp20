#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void print_collection(const T& collection)
{
	std::cout << "collection [";
	for (const auto& e : collection)
		std::cout << " " << e;
	std::cout << " ]" << std::endl;
}

int main()
{
	std::vector<int> numbers{ 11, 2, 6, 4, 8, 3, 17, 9 };
	print_collection(numbers);

	// std::ranges::all_of
	std::cout << std::endl;
	std::cout << "std::ranges::all_of():" << std::endl;

	auto odd = [](int n) {return n % 2 != 0; };

	auto result = std::ranges::all_of(numbers, odd);

	if (result)
		std::cout << "All elements in numbers are odd" << std::endl;
	else
		std::cout << "Not all elements in numbers are odd" << std::endl;

	std::cout << "\n================================================\n\n";

	// std::ranges::for_each
	std::cout << std::endl;
	std::cout << "std::ranges::for_each():" << std::endl;
	print_collection(numbers);
	std::ranges::for_each(numbers, [](int& n) {return n *= 2; });
	print_collection(numbers);

	std::cout << "\n================================================\n\n";

	// std::ranges::sort
	std::cout << std::endl;
	std::cout << "std::ranges::sort():" << std::endl;
	print_collection(numbers);
	std::ranges::sort(numbers, std::greater<int>());
	print_collection(numbers);

	std::cout << "\n================================================\n\n";

	// std::ranges::find
	std::cout << std::endl;
	std::cout << "std::ranges::find():" << std::endl;

	numbers = { 11, 2, 6, 4, 8, 3, 17, 9 };

	auto odd_n_position = std::ranges::find_if(numbers, odd);


	if (odd_n_position != numbers.end())
		std::cout << "numbers contains at least one odd number: " << *odd_n_position <<
		" at position: " << odd_n_position - numbers.begin() << std::endl;
	else
		std::cout << "numbers doesn't contain any odd number" << std::endl;

	std::cout << "\n================================================\n\n";

	// Important, copying into output stream on fly
	std::cout << std::endl;
	std::cout << "std::ostream_iterator:" << std::endl;
	std::ranges::copy(numbers, std::ostream_iterator<int>(std::cout, ","));
	std::cout << static_cast<char>(8); // Trick to delete last comma







	return 0;
}