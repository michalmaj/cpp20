#include <iostream>
#include <windows.h>

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	// Capture list
	double a{ 10 };
	double b{ 20 };

	auto func = [a, b]()
	{
		std::cout << "a + b: " << a + b << std::endl;
	};
	func();

	std::cout << "\n=========================\n\n";

	// Capturing by value
	int c{ 42 };

	auto func1 = [c, h]()
	{
		
		SetConsoleTextAttribute(h, 2);
		std::cout << "Inner value: " << c << ", &inner: " << c << std::endl;
	};

	for(size_t i{}; i < 5; ++i)
	{
		std::cout << "Outer value: " << c << ", &outer: " << c << std::endl;
		func1();
		SetConsoleTextAttribute(h, 7);
		++c;
	}

	std::cout << "\n=========================\n\n";

	// Capture by reference
	int d{ 16 };

	auto func2 = [&d, h]()
	{

		SetConsoleTextAttribute(h, 2);
		std::cout << "Inner value: " << d << ", &inner: " << d << std::endl;
	};

	for (size_t i{}; i < 5; ++i)
	{
		std::cout << "Outer value: " << d << ", &outer: " << d << std::endl;
		func2();
		SetConsoleTextAttribute(h, 7);
		++d;
	}




	return 0;
}