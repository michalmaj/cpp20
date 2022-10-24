#include <iostream>

template<typename T>
T maximum(T a, T b)
{
	return (a > b) ? a : b;
}

int main()
{
	int a{ 10 };
	int b{ 23 };
	double c{ 34.7 };
	double d{ 23.4 };
	std::string e{ "Hello" };
	std::string f{ "World" };

	auto max_int = maximum(a, b); // int type deduce
	std::cout << "max_int: " << max_int << std::endl;


	auto max_double = maximum(c, d); // double type deduce
	std::cout << "max_double: " << max_double << std::endl;


	auto max_str = maximum(e, f); // string type deduce
	std::cout << "max_str: " << max_str << std::endl;


	maximum<double>(c, d); // explicitly say that we want the double version called, if an
							   // instance is not there already, it will be created.

	maximum<double>(a, c); // Works, even if parameters are of different types
							 // there is implicit conversion from int to double
							 // for the first parameter

	//maximum<double>(a, e); // Compiler Error, can't convert std::string to double

	return 0;
}