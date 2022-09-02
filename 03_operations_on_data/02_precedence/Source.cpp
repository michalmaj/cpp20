/*
 * If there are multiple operators in a single expression,
 * the operations are not evaluated simultaneously.
 * Rather, operators with higher precedence have their operations evaluated first.
 * More on: https://en.cppreference.com/w/cpp/language/operator_precedence
 * From math perspective we have PEMDAS:
 *      P - Parentheses
 *      E - Exponents (ie., Powers and Square Roots, etc.)
 *      MD - Multiplication and Division (left-to-right)
 *      AS - Addition and Subtraction (left-to-right)
 */

#include <iostream>


int main()
{
    int a{ 6 };
    int b{ 3 };
    int c{ 8 };
    int d{ 9 };
    int e{ 3 };
    int f{ 2 };
    int g{ 5 };

    
    int result = a + b * c - d / e - f + g;

    // PEMDAS - multiplication and division (left to right),
    // then addition and subtraction (left to right)
    std::cout << "result: " << result << std::endl;

    // PEMDAS - multiplication and division (left to right),
    // then addition and subtraction (left to right)
    result = a / b * c + d - e + f;
    std::cout << "result: " << result << std::endl;

    // PEMDAS - Parentheses, then multiplication and division (left to right),
    // then addition and subtraction (left to right)
    result = (a + b) * c - d / e - f + g;
    std::cout << "result: " << result << std::endl;
	return 0;
}