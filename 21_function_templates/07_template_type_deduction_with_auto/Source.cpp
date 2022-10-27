#include <iostream>
#include <variant>

// Largest type will be deduced
template <typename T, typename P>
auto maximum(T a, P b)
{
	return (a > b) ? a : b;
}


int main()
{
	auto max1 = maximum('e', 33); // double return type deduced
	std::cout << "max1 : " << max1 << std::endl;
	std::cout << "size of max1 : " << sizeof(max1) << std::endl;


	return 0;
}