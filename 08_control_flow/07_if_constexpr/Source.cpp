/*
 * Constexpr if
 * The statement that begins with if constexpr is known as the constexpr if statement.
 *
 */

#include <iostream>

int main()
{
	constexpr bool condition{ false };

	if constexpr (condition)
		std::cout << "Condition is true\n";
	else
		std::cout << "Condition is false\n";


	return 0;
}