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

	// Destination box - must be same size as source box 
	BoxContainer<int> box2(box1.size(), 0); // Own constructor

	//// We can fill up using for loop or create constructor for that
	//for (size_t i{}; i < box1.size(); ++i)
	//	box2.add(0);

	std::cout << "box2-1: " << box2 << std::endl;
	std::ranges::copy(box1.begin(), box1.end(), box2.begin());
	std::cout << "box2-2: " << box2 << std::endl;




	return 0;
}