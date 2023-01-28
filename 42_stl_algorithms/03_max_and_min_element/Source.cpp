#include <iostream>
#include <algorithm>
#include <vector>
#include <list>


int main()
{
	/*std::vector<int> v{ 3, 400, 51, 6, 7, 23, 56, 71 };*/
	//std::list<int> v{ 3, 400, 51, 6, 7, 23, 56, 71 };
	int v[]{ 3, 400, 51, 6, 7, 23, 56, 71 };


	// max_element and min_element return an iterator to the found element 
	auto result = std::max_element(std::begin(v), std::end(v));
	std::cout << "max element is: " << *result << std::endl;

	result = std::min_element(std::begin(v), std::end(v));
	std::cout << "min element is: " << *result << std::endl;

	std::cout << "\n==================================================\n\n";

	// Distance: closet and furthest
	int number_to_find{ 67 };

	auto distance = [number_to_find](int x, int y)
	{
		return (std::abs(x - number_to_find) < std::abs(y - number_to_find));
	};


	// Finding the closest
	result = std::min_element(std::begin(v), std::end(v), distance);
	std::cout << *result << " is closest to " << number_to_find << std::endl;

	// Finding the furthest
	result = std::max_element(std::begin(v), std::end(v), distance);
	std::cout << *result << " is furthest from " << number_to_find << std::endl;

	std::cout << "\n==================================================\n\n";

	// Capturing min and max in pair object with the auto syntax
	auto [near, far] = std::minmax_element(std::begin(v), std::end(v), distance);
	std::cout << *near << " is closest to " << number_to_find << std::endl;
	std::cout << *far << " is furthest from " << number_to_find << std::endl;


	return 0;
}