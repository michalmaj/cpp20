#include <iostream>

//// Passing by value
//template <class T>
//T maximum(T a, T b)
//{
//	std::cout << "Inside &a: " << &a << std::endl;
//	return (a > b) ? a : b;
//}

// Passing by reference
template <class T>
T& maximum(const T& a, const T& b)
{
	std::cout << "Inside &a: " << &a << std::endl;
	return (a > b) ? a : b;
}

int main()
{
	double a{ 51.2 };
	double b{ 23.5 };

	std::cout << "Outside &a: " << &a << std::endl;
	//auto result = maximum(a, b); // For non reference function
	auto& result = maximum(a, b);
	std::cout << "Outside &result: " << &result << std::endl;


	return 0;
}