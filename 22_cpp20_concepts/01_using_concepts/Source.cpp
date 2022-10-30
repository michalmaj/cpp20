/*
 * Concepts is a mechanism to place constraints on our template type parameters
 *
 * Documentation:
 * https://en.cppreference.com/w/cpp/concepts
 */

#include <iostream>
#include <concepts>
#include <type_traits>

/**
 * \brief Template function for adding two values, that has a concept which allows only for integral type
 * \tparam T Any integral type.
 * \param a First value.
 * \param b Second value.
 * \return Sum of a + b.
 */
//// Syntax 1 (uncomment one oth them):
//template <typename T>
//requires std::integral<T>
//T add(T a, T b)
//{
//	return a + b;
//}

//// Syntax 2:
//template <std::integral T> // Instead of use of requires keyword, we can directly put std::integral into brackets (dropping typename keyword)
//T add(T a, T b)
//{
//	return a + b;
//}

//// Syntax 3:
//auto add(std::integral auto a, std::integral auto b) // This time we can mark auto with std::integral
//{
//	return a + b;
//}

//// Syntax 4:
//template <typename T>
//T add(T a, T b) requires std::integral<T> // Put our requirements after parameter list
//{
//	return a + b;
//}

// Syntax 5:
template <typename T>
requires std::is_integral_v<T> // It's also possible to use type traits to set our requirements up 
T add(T a, T b)
{
	return a + b;
}

int main()
{
	char a_0{ 10 };
	char a_1{ 20 };

	auto result_a = add(a_0, a_1);
	std::cout << "result_a: " << static_cast<int>(result_a) << std::endl;

	int b_0{ 5 };
	int b_1{ 11 };

	auto result_b = add(b_0, b_1);
	std::cout << "result_b: " << result_b << std::endl;

	//// After mark template function using concepts, we can't pass double type.
	//// Constrains was set as integral type.
	//double c_0{ 11.1 };
	//double c_1{ 1.9 };

	//auto result_c = add(c_0, c_1);
	//std::cout << "result_c: " << result_c << std::endl;

	return 0;
}