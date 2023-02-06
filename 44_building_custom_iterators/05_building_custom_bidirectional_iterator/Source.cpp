#include <iostream>
#include <algorithm>
#include "boxcontainer.h"



int main()
{
	BoxContainer<int> box1{ 5, 1, 4, 2, 8, 3, 7, 9, 6 };

	//std::cout << "box1: " << box1 << std::endl;
	//std::ranges::reverse(box1);
	//std::cout << "box1: " << box1 << std::endl;

	std::cout << "box1-reverse: ";
	for (auto it = box1.end(); it != box1.begin();)
		std::cout << *(--it) << " ";
	std::cout << std::endl;


	return 0;
}