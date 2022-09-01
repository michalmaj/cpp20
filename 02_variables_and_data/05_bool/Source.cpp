/*
 * Boolean can store two states: true or false.
 * In memory it occupies 8 bits.
 */

#include <iostream>


int main()
{
	bool red{ true };
	bool green{ false };

	if (red == true)
		std::cout << "Stop!" << std::endl;
	else
		std::cout << "Go through!" << std::endl;

	// if we change states
	green = true;
	red = false;

	// we don't need to write explicit == true
	if (green)
		std::cout << "The light is green!" << std::endl;
	else
		std::cout << "The light is red!" << std::endl;

	// sizeof bool
	std::cout << "sizeof(bool): " << sizeof(bool) << std::endl;

	// print bool values
	// true will be print as 1
	// false will be print as 0
	std::cout << std::endl;
	std::cout << "red: " << red << std::endl;
	std::cout << "green: " << green << std::endl;

	// but we can use std::boolalpha to force cout to show true/false
	std::cout << std::boolalpha;
	std::cout << "red: " << red << std::endl;
	std::cout << "green: " << green << std::endl;


	return 0;
}