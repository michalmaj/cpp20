#include <iostream>
#include <vector>

template <typename T>
void print_collection(const T& collection)
{
	auto it = collection.begin();

	std::cout << "[";
	while (it != collection.end())
	{
		std::cout << " " << *it;
		++it;
	}
	std::cout << " ]" << std::endl;
}

int main()
{
	std::vector<int> numbers{ 11, 22, 33, 44, 55, 66, 77 };

	std::cout << "numbers: ";
	print_collection(numbers);

	std::vector<int>::iterator it = numbers.begin();

	while (it != numbers.end())
	{
		*it = 100;
		++it;
	}
	std::cout << "numbers: ";
	print_collection(numbers);

	std::cout << "\n==================================================\n\n";

	numbers = { 11, 22, 33, 44, 55, 66, 77 };

	// All three declarations will work
	//std::vector<int>::const_iterator c_it = numbers.cbegin();
	//std::vector<int>::const_iterator c_it = numbers.begin();
	auto c_it = numbers.cbegin();

	while (c_it != numbers.end())
	{
		//*c_it = 100; // Compiler Error
		++c_it;
	}
	std::cout << "numbers: ";
	print_collection(numbers);

	std::cout << "\n==================================================\n\n";

	// Constant reverse iterator

	// All three declarations will work
	//std::vector<int>::const_reverse_iterator cr_it = numbers.crbegin();
	//std::vector<int>::const_reverse_iterator cr_it = numbers.rbegin();
	auto cr_it = numbers.crbegin();

	while (cr_it != numbers.crend())
	{
		//*cr_it == 600; // Compiler error: cr_it is a const iterator, can't modify data through it
		++cr_it;
	}


	return 0;
}