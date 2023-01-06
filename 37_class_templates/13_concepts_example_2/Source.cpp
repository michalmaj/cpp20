#include <iostream>
#include <concepts>

template <typename T>
concept Number = (std::integral<T> or std::floating_point<T>)
				  and !std::same_as<T, bool>
				  and !std::same_as<T, char>;

template <Number T, Number U>
auto add(T a, U b)
{
	return a + b;
}

int main()
{
	static_assert(Number<bool>);

	auto result1 = add(10, 20);
	std::cout << "result1: " << result1 << std::endl;

	//auto result2 = add('c', 20);
	//std::cout << "result2: " << result2 << std::endl;

	auto result3 = add(20.1, 20);
	std::cout << "result3: " << result3 << std::endl;

	return 0;
}