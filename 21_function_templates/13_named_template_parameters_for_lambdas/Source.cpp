#include <iostream>
#include <typeinfo>

int main()
{

	auto func = [](auto a, auto b)
	{
		return a + b;
	};

	auto func1 = []<typename T, typename P>(T a, P b)
	{
		return a + b;
	};

	int a{ 5 };
	double b{ 63.9 };

	auto result = func(a, b);

	std::cout << "result: " << result << ", sizeof(result): " << sizeof(result)
		<< ", type name: " << typeid(result).name() << std::endl;

	int c{ 2 };
	float d{ 2.2f };
	auto result1 = func1(c, d);
	std::cout << "result1: " << result1 << ", sizeof(result1): " << sizeof(result1)
		<< ", type name: " << typeid(result1).name() << std::endl;

	return 0;
}