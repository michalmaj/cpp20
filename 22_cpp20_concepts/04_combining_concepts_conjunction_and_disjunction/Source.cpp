#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires(T t)
{
	sizeof(t) <= 4; // Simple requirement
		requires sizeof(t) <= 4; // Nested requirement
};

template<typename T>
//requires std::integral<T> || std::floating_point<T> // You can only call this function with integer or floating point arguments.
//requires std::integral<T> && TinyType<T>
requires std::integral<T> and requires(T t) // Same as above
{
	sizeof(t) <= 4; // Simple requirement
		requires sizeof(t) <= 4; // Nested requirement
}
T add(T a, T b)
{
	return a + b;
}

int main()
{
	//// For first requirement: requires std::integral<T> || std::floating_point<T>
	////// Will work, x and y are integers
	////int x{ 6 };
	////int y{ 4 };

	//// Will work x and y are floating point variables
	//double x{ 6.2 };
	//double y{ 4.9 };

	////// Won't work, std::string isn't an integral or floating point type. 
	////std::string x{ "Hello" };
	////std::string y{ "World" };
	//
	//add(x, y);


	// For first requirement: requires std::integral<T> && TinyType<T>
	// Will work, x and y are integers
	int x{ 6 };
	int y{ 4 };

	//// Won't work, even if x and y are integers, but they aren't a small type (<=4) - violate TinyType concept
	//long long int x{ 6 };
	//long long int y{ 4 };

	//// Won't work x and y are floating point variables
	//double x{ 6.2 };
	//double y{ 4.9 };

	//// Won't work, std::string isn't an integral or floating point type. 
	//std::string x{ "Hello" };
	//std::string y{ "World" };

	add(x, y);

	return 0;
}