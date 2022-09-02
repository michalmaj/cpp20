/*
 * Pre-increment and pre-decrement operators increments or decrements
 * the value of the object and returns a reference to the result. For this we
 * will use ++ or -- before variable.
 *
 * Post-increment and post-decrement creates a copy of the object,
 * increments or decrements the value of the object and returns
 * the copy from before the increment or decrement. For this we will
 * use ++ or -- after variable.
 */

#include <iostream>

int main()
{
	int value{ 5 };

	// increment by 1
	value = value + 1; // now value is 6
	std::cout << "Value: " << value << std::endl; // 6

	value = 5; // now value is 5

	// decrement by 1
	value = value - 1; // 4
	std::cout << "Value: " << value << std::endl; // 4


	//===============================


	std::cout << std::endl;

	// postfix increment and decrement
	std::cout << "postfix increment and decrement:" << std::endl;

	value = 5;

	std::cout << "Postfix increment: " << value++ << std::endl; // 5
	std::cout << "Value: " << value << std::endl; // 6

	value = 5;

	std::cout << "Postfix decrement: " << value-- << std::endl; // 5
	std::cout << "Value: " << value << std::endl; // 4


	std::cout << std::endl;

	// prefix increment and decrement
	std::cout << "prefix increment and decrement:" << std::endl;

	value = 5;

	std::cout << "Prefix increment: " << ++value << std::endl; // 6
	std::cout << "Value: " << value << std::endl; // 6

	value = 5;

	std::cout << "Prefix decrement: " << --value << std::endl; // 4
	std::cout << "Value: " << value << std::endl; // 4


	return 0;
}