#include <iostream>
#include "boxcontainer.h"

// Template type alias
template <typename T>
using compare_T = bool(*)(const T&, const T&);

template <typename T>
T get_best(const BoxContainer<T>& collection, compare_T<T> comparator)
{
	T best = collection.get_item(0);
	for(size_t i{1}; i < collection.size(); ++i)
	{
		if(comparator(collection.get_item(i), best))
		{
			best = collection.get_item(i);
		}
	}

	return best;
}

bool larger_in_size(const std::string& str1, const std::string& str2)
{
	return (str1.size() > str2.size()) ? true : false;
}

bool larger_lexicographically(const std::string& str1, const std::string& str2)
{
	return (str1 > str2);
}

bool larger_int(const int& param1, const int& param2)
{
	return (param1 > param2);
}

// Templated callback function
template <typename T>
bool smaller(const T& param1, const T& param2)
{
	return (param1 < param2) ? true : false;
}

int main()
{
	BoxContainer<std::string> quote;
	quote.add("The");
	quote.add("sky");
	quote.add("is");
	quote.add("blue");
	quote.add("my");
	quote.add("friend");

	std::cout << std::endl;
	std::cout << "Getting the best: " << std::endl;
	std::cout << "Larger in size: " << get_best(quote, larger_in_size) << std::endl;
	std::cout << "Greater lexicographically: " << get_best(quote, larger_lexicographically) << std::endl;

	std::cout << "\n==================================================\n\n";

	BoxContainer<int> ints;
	ints.add(1);
	ints.add(3);
	ints.add(451);
	ints.add(23);
	ints.add(4);

	std::cout << "Larger int: " << get_best(ints, larger_int) << std::endl;
	std::cout << "Smaller int: " << get_best(ints, smaller) << std::endl;




	return 0;
}