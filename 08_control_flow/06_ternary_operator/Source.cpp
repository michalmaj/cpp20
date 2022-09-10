/*
 * Conditional operator
 * The conditional operator expressions have the form:
 *		E1 ? E2 : E3
 *
 * The first operand of the conditional operator is evaluated and contextually converted
 * to bool. After both the value evaluation and all side effects of the first operand are
 * completed, if the result was true, the second operand is evaluated. If the result was
 * false, the third operand is evaluated. 
 */

#include <iostream>
#include <typeinfo>

int main()
{

	int max{};

	int a{ 35 };
	int b{ 20 };

	std::cout << std::endl;
	std::cout << "using regular if" << std::endl;
	if (a > b)
		max = a;
	else
		max = b;

	std::cout << "max: " << max << std::endl;

	// ternary operator
	max = (a > b) ? a : b;

	std::cout << "max: " << max << std::endl;

	// Watch out for explicit conversion, it's always pick the bigger type in memory.
	// Even if a is greater than b, max1 will be float type
	auto max1 = (a > b) ? a : 22.5f;

	std::cout << "max1: " << max1 << " has a type: " << typeid(max1).name() << std::endl;
	

	return 0;
}