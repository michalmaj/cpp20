#include <iostream>
#include <type_traits>

template<typename T>
void print_number(T n)
{
	static_assert(std::is_integral_v<T>, "print_number() can only be called with integral types");
	std::cout << "number: " << n << std::endl;
}

int main()
{
	std::cout << std::boolalpha;
	std::cout << "std::is_integral<int>::value: " << std::is_integral<int>::value << std::endl;
	std::cout << "std::is_floating_point<int>::value: " << std::is_floating_point<int>::value << std::endl;

	std::cout << "\n=================================\n\n";

	std::cout << "std::is_integral_v<int>: " << std::is_integral_v<int> << std::endl;
	std::cout << "std::is_floating_point_v<int>: " << std::is_floating_point_v<int> << std::endl;

	std::cout << "\n=================================\n\n";

	int a{ 7 };
	print_number(a);

	std::cout << "\n=================================\n\n";

	auto func = []<typename T>(T a, T b)
	{
		static_assert(std::is_integral_v<T>, "func can only be called with integral types");
		return a + b;
	};

	int x{ 7 };
	int y{ 6 };
	func(x, y);

	return 0;
}