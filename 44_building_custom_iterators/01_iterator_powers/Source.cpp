#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& vec)
{
	out << "[";
	for (const auto& e : vec)
		out << " " << e;
	out << " ]";
	return out;
}

int main()
{
	// Source collection
	std::vector<int> numbers{ 1, 9, 3, 7, 2, 5, 4, 6, 89 };
	std::cout << "numbers: " << numbers << std::endl;
	
	// Iterators returned by begin() are input iterators. The requirement is that we are
	// able to read through them. That's all std::ranges::find needs
	if (std::ranges::find(numbers.cbegin(), numbers.cend(), 8) != numbers.end())
		std::cout << "numbers contains: " << 8 << std::endl;
	else
		std::cout << "numbers doesn't contain " << 8 << std::endl;

	// Output iterator: std::ranges::copy
	// Iterator through we can write
	std::vector<int> dest(numbers.size());
	//std::vector<int> dest; // BAD! Probably a crash (but we can use std::back_inserter)

	std::cout << "numbers: " << numbers << std::endl;
	std::cout << "dest: " << dest << std::endl;

	// dest begin() has to be an output iterator, have to be able to write through it
	//std::ranges::copy(numbers.begin(), numbers.end(), dest.cbegin()); // Compiler Error - it isn't an output iterator
	std::ranges::copy(numbers.cbegin(), numbers.cend(), dest.begin()); // Works fine
	//std::ranges::copy(numbers.begin(), numbers.end(), std::back_inserter(dest)); // std::back_inserter version

	std::cout << "numbers: " << numbers << std::endl;
	std::cout << "dest: " << dest << std::endl;

	// Forward iterator: std::ranges::replace, std::ranges::fill
	std::cout << "numbers: " << numbers << std::endl;

	// Replace every instance of 7 with 345. The iterator needs an
	// operator++ to move forward.
	std::ranges::replace(numbers.begin(), numbers.end(), 7, 345);
	std::cout << "numbers: " << numbers << std::endl;

	// Bidirectional iterator
	std::cout << "numbers: " << numbers << std::endl;
	auto it_first = numbers.begin();
	auto it_last = numbers.end();

	while (it_last != it_first)
	{
		it_last--;
		std::cout << *it_last << " ";
	}
	std::cout << std::endl;

	std::ranges::reverse(numbers);
	std::cout << "numbers: " << numbers << std::endl;

	// Random access iterator: std::ranges::sort
	std::cout << "numbers: " << numbers << std::endl;

	// Sorting the collection
	std::ranges::sort(numbers);
	std::cout << "numbers: " << numbers << std::endl;





	return 0;
}