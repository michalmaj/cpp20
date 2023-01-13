#include <iostream>

int main()
{
	int a{ 7 };
	int b{ 3 };
	int some_var{ 23 }; // Not captured by the [=] lambda, so it won't set up a member var for this
	double some_other_var{ 55.5 }; // Not captured by the [=] lambda, so it won't set up a member var for this

	// Capturing a few variables by value
	auto func = [a, b](int c, int d) /*mutable*/
	{
		//++a; // As long as there is no mutable keyword after parameter list capture variables are immutable 
		std::cout << "Captured values:" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		std::cout << std::endl;

		std::cout << "Parameters:" << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "d: " << d << std::endl;
	};
	func(10, 20);

	std::cout << "\n======================================================\n\n";

	// Capturing everything by value
	auto func1 = [=](int c, int d) /*mutable*/
	{
		//++a; // As long as there is no mutable keyword after parameter list capture variables are immutable 
		std::cout << "Captured values:" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		std::cout << std::endl;

		std::cout << "Parameters:" << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "d: " << d << std::endl;
	};
	func1(10, 30);

	return 0;
}