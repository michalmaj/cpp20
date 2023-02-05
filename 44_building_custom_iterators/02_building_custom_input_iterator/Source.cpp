#include <iostream>
#include <algorithm>
#include <vector>
#include "boxcontainer.h"

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
	out << "[";
	for (const auto& e : vec)
		out << " " << e;
	out << " ]";

	return out;
}


int main()
{
	//std::vector<int> box1{ 8, 1, 4, 2, 5, 3, 7, 9 };

	BoxContainer<int> box1{ 5, 1, 4, 2, 8, 3, 7, 9, 6 };

	std::cout << "box: " << box1 << std::endl;

	//Find algorithm
	auto result = std::ranges::find(box1, 8);
	if (result != box1.end())
		std::cout << "number contains: " << 8 << std::endl;
	else
		std::cout << "numbers does not contain: " << 8 << std::endl;

	// Range base for loop
	for (const auto& n : box1)
		std::cout << n << " ";
	std::cout << std::endl;

	//std::ranges::reverse(box1.begin(), box1.end());




	return 0;
}