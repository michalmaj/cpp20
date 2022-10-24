/*
 * Templates:
 * Templates:
 *  - Function templates are just blueprints, they're not real function declaration and definition.
 *	- Real function declaration and definition (template instances) are created when we call
 *	  the function with arguments.
 *	- If the template parameters are of the same type (T, T), then arguments we call when we call
 *	  the function with also must match, otherwise we get a compiler error.
 *	- The arguments passed to a function template must support the operations that are done in the
 *	  body of the function.
 */

#include <iostream>

// Forced to use the same type for return type and both parameters
template <typename T>
T maximum(T a, T b)
 {
	return (a > b) ? a : b;
}

template<typename T>
T multiply(T a, T b)
{
	return a * b;
}

int main()
{
	// Maximum
	int x{ 5 };
	int y{ 7 };
	auto result = maximum(x, y);
	std::cout << "result: " << result << std::endl;

	double x1{ 5.5 };
	double y1{ 78.7 };
	auto result1 = maximum(x1, y1);
	std::cout << "result1: " << result1 << std::endl;

	std::string x2{ "Hello"};
	std::string y2{ "World"};
	auto result2 = maximum(x2, y2);
	std::cout << "result2: " << result2 << std::endl;

	std::cout << "\n============================================\n\n";

	// Multiplication
	result = multiply(x, y);
	std::cout << "result: " << result << std::endl;

	result1 = multiply(x1, y1);
	std::cout << "result1: " << result1 << std::endl;

	//result2 = multiply(x2, y2); // Compiler Error, multiplication won't work for std::string
	//std::cout << "result2: " << result2 << std::endl;

	//auto result3 = maximum(x, y1); // Compiler Error, two different type argument passed

	// Pointers
	int* p_x{ &x };
	int* p_y{ &y };

	auto result4 = maximum(p_x, p_y); // We don't get what we want, we will compare addresses
	std::cout << "result4: " << result4 << std::endl;



	return 0;
}