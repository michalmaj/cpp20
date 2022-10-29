#include <iostream>
#include <typeinfo>

//// This function can be write using templates
//auto func_add(auto a, auto b)
//{
//	return a + b;
//}

// Like this
template <typename T, typename P>
decltype(auto) func_add(T a, P b)
{
	return a + b;
}

int main()
{
	int a{ 22 };
	double b{ 2.2 };

	auto result = func_add(a, b);
	std::cout << "result: " << result << ", sizeof(result): " << sizeof(result)
		<< ", type name: " << typeid(result).name() << std::endl;


	return 0;
}