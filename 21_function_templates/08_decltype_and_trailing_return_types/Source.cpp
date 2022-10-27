#include <iostream>
#include <typeinfo>

// In this case we can split to declaration and definition
// Declaration:
template <typename T, typename P>
auto maximum(T a, P b) -> decltype((a > b) ? a : b);

int main()
{
	// decltype
	int a{ 9 };
	double b{ 5.5 };

	std::cout << "size: " << sizeof(decltype((a > b) ? a : b)) << ", type: "
		<< typeid(decltype((a > b) ? a : b)).name() << std::endl;

	decltype((a > b) ? a : b) c{ 7 };
	std::cout << "c: " << c << ", size: " << sizeof(c) << ", type: "
		<< typeid(c).name() << std::endl;

	std::cout << "\n==========================================\n\n";

	auto result = maximum(a, b);
	std::cout << "result: " << result << ", size: " << sizeof(result) << ", type: "
		<< typeid(result).name() << std::endl;



	return 0;
}

// Definition
template <typename T, typename P>
auto maximum(T a, P b) -> decltype((a > b) ? a : b)
{
	return (a > b) ? a : b;
}