/*
 * Lambda function signature:
 *							[capture list] (parameters) -> return type{
 *								// Function body
 *							}
 */
#include <iostream>
#include <typeinfo>

int main()
{

	// Declaring a lambda function and calling it through a name
	auto func = []()
	{
		std::cout << "Hello World" << std::endl;
	};

	func();
	func();

	std::cout << "\n===========================================\n\n";

	// Declare a lambda function and call it directly
	[]()
	{
		std::cout << "Hello World directly call" << std::endl;
	}();

	std::cout << "\n===========================================\n\n";

	// Lambda functions that takes parameters
	[](double a, double b)
	{
		std::cout << "a + b: " << (a + b) << std::endl;
	}(10.2, 4.6);

	std::cout << "\n===========================================\n\n";

	auto func1 = [](double a, double b)
	{
		std::cout << "a + b: " << (a + b) << std::endl;
	};

	func1(10.2, 4.6);
	func1(5, 7);

	std::cout << "\n===========================================\n\n";

	// Lambda functions that return something
	auto result = [](double a, double b)
	{
		return a + b;
	}(10, 20);

	std::cout << "result: " << result << std::endl;
	std::cout << "result: " << [](double a, double b) {return a + b; }(10, 60) << std::endl;

	std::cout << "\n===========================================\n\n";

	auto func2 = [](double a, double b)
	{
		return a + b;
	};

	auto result1 = func2(23, 7);
	auto result2 = func2(9, 45);

	std::cout << "result1: " << result1 << std::endl;
	std::cout << "result2: " << result2 << std::endl;
	std::cout << "direct call: " <<func2(5, 2) << std::endl;

	std::cout << "\n===========================================\n\n";

	// Explicit specify the return type
	auto func3 = [](double a, double b) -> int
	{
		return a + b;
	};

	auto func4 = [](double a, double b)
	{
		return a + b;
	};

	double a{ 6.9 };
	double b{ 3.5 };

	auto result3 = func3(a, b);
	auto result4 = func4(a, b);

	std::cout << "result3: " << result3 << ", sizeof(result3): " << sizeof(result3)
		<< ", type of result3: " << typeid(result3).name() << std::endl;

	std::cout << "result4: " << result4 << ", sizeof(result4): " << sizeof(result4)
		<< ", type of result4: " << typeid(result4).name() << std::endl;

	std::cout << "\nDone!" << std::endl;

	return 0;
}