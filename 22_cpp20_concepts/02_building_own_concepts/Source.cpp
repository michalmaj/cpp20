#include <iostream>
#include <concepts>
#include <type_traits>

// We are able to create own concepts

// Syntax 1:
template <typename T>
concept MyIntegral = std::is_integral_v<T>; // Create own concepts

//template <typename T>
//requires MyIntegral<T>
//T add(T a, T b)
//{
//	return a + b;
//}

//// Other version of above function
//template <MyIntegral T>
//
//T add(T a, T b)
//{
//	return a + b;
//}

//// Other version of above function
//template <typename  T>
//T add(T a, T b) requires MyIntegral<T>
//{
//	return a + b;
//}

// Other version of above function
MyIntegral auto add(MyIntegral auto a, MyIntegral auto b)
{
	return a + b;
}

// Syntax 2
template <typename T>
concept Multipliable = requires(T a, T b)
{
	a * b; // Fail if a or b not support operator*
};

template <typename T>
requires Multipliable<T>
T sum1(T a, T b)
{
	return a * b;
}

template <typename T>
concept Incrementable = requires(T a)
{
	a += 1;
	a++;
	++a;
};

template <typename T>
	requires Incrementable<T>
T sum2(T a, T b)
{
	return a * b;
}

int main()
{

	int x{ 6 };
	int y{ 7 };

	add(x, y);

	//// Won't work, because our template function has a requires for only integer types 
	//double a{ 6.7 };
	//double b{ 23.4 };
	//add(a, b);

	double i{ 2.3 };
	double j{ 54.2 };
	sum1(i, j);

	//// Won't work
	//std::string s1{ "Hello" };
	//std::string s2{ "World" };
	//sum1(s1, s2);
	//sum2(s1, s2);

	return 0;
}