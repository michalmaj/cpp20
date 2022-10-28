#include <iostream>
#include <typeinfo>

// Our return type is now explicitly set as a double
template <typename ReturnType = double, typename T, typename P>
ReturnType maximum(T a, P b)
{
	return (a > b) ? a : b;
}

template <typename T, typename P, typename ReturnType=double>
ReturnType minimum(T a, P b)
{
	return (a < b) ? a : b;
}

int main()
{
	int a{ 6 };
	double b{ 9.5 };

	auto result = maximum<int>(a, b);
	std::cout << "result: " << result << ", sizeof(result): " << sizeof(result)
		<< ", type info: " << typeid(result).name() << std::endl;

	auto result1 = minimum<int, double, float>(a, b);
	std::cout << "result1: " << result1 << ", sizeof(result1): " << sizeof(result)
		<< ", type info: " << typeid(result1).name() << std::endl;



	return 0;
}