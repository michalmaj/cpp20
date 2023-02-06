#include <iostream>
#include <algorithm>
#include "boxcontainer.h"



int main()
{
	BoxContainer<int> box1{ 5, 1, 4, 2, 8, 3, 7, 9, 6 };

	std::cout << "box1: " << box1 << std::endl;
	std::ranges::sort(box1);
	std::cout << "box1: " << box1 << std::endl;


	return 0;
}