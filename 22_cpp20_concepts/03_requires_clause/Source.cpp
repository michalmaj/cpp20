#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires(T t)
{
	sizeof(T) <= 4; // Simple requirement: Only enforces syntax
		requires sizeof(T) <= 4; // Now we can use only types that have less than or equal to 4 bytes.
};

// Compound requirement
template <typename T>
concept Addable = requires(T a, T b)
{
	// noexcept is optional
	{a + b} noexcept -> std::convertible_to<int>; // Compound requirements
	// Checks if a + b is valid syntax, doesn't throw exceptions(optional), and the result
	// is convertible to int(optional) 
};


//TinyType auto add(TinyType auto a, TinyType auto b)
//{
//	return a + b;
//}

Addable auto add(Addable auto a, Addable auto b)
{
	return a + b;
}

int main()
{
	double x{ 67 };
	double y{ 56 };

	//std::string x{ "Hello" };
	//std::string y{ "World" };

	auto result = add(x, y);

	std::cout << "result: " << result << std::endl;
	std::cout << "sizeof(result): " << sizeof(result) << std::endl;

	return 0;
}