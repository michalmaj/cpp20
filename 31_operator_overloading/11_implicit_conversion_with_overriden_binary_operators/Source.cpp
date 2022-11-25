#include <iostream>
#include "number.h"

int main()
{
	Number n1{ 22 };

	std::cout << n1 << std::endl;
	std::cout << "n1 + 2: " << (n1 + 2) << std::endl;
	std::cout << "2 + n1: " << (2 + n1) << std::endl; // Won't work if operator+ is a member function
	std::cout << "2 - n1: " << (2 - n1) << std::endl; // Will work, because operator- is a non-member
														// function and allows to implicit conversion 

	return 0;
}