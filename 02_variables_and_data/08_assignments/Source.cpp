/*
 * Remember that in C++ is prefer to initialize value using curly braces {}.
 * But is you want to change value, you still need to use assignment sign =.
 */

#include <iostream>

int main()
{
	int var1{ 123 }; // declare and initialize in preferred way
	std::cout << "var1: " << var1 << std::endl;

	var1 = 55; // assign new value
	std::cout << "var1: " << var1 << std::endl;

	std::cout << std::endl;

	double var2{ 44.55 }; // declare and initialize in preferred way
	std::cout << "var2: " << var2 << std::endl;

	var2 = 99.99; // assign new value
	std::cout << "var2: " << var2 << std::endl;

	std::cout << std::endl;

	bool state{ false };
	std::cout << std::boolalpha;
	std::cout << "state: " << state << std::endl;

	state = true;
	std::cout << "state: " << state << std::endl;

	std::cout << std::endl;

	// warning some problems with auto
	auto var3{ 333u }; // declare and initialize as unsigned

	var3 = -33; // trying to put negative value in unsigned variable
	std::cout << "var3: " << var3 << std::endl; // garbage without compiler error

	return 0;
}