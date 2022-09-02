/*
 * Logical operators are used to determine the logic between variables or values.
 * Returns the result of a boolean operation.
 * We have three logical operators:
 *		And - &&, evaluate to true when all operands are true
 *		OR - ||, evaluate to true, when one of operands is true
 *		NOT - !, flip actual state.
 *
 * More at: https://en.cppreference.com/w/c/language/operator_logical
 */

#include <iostream>

int main()
{
	bool a{ true };
	bool b{ false };
	bool c{ true };

	std::cout << std::boolalpha; // let us print true/false instead of 1/0
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	// AND: Single false operand will drag
	// the entire expression to evaluating false
	std::cout << std::endl;
	std::cout << "Examples of AND operations:" << std::endl;

	std::cout << "a && b: " << (a && b) << std::endl;
	std::cout << "a && c: " << (a && c) << std::endl;
	std::cout << "a && b && c: " << (a && b && c) << std::endl;

	// OR: Single true operand will drag
	// the entire expression to evaluating true
	std::cout << std::endl;
	std::cout << "Examples of OR operations:" << std::endl;

	std::cout << "a || b: " << (a || b) << std::endl;
	std::cout << "a || c: " << (a || c) << std::endl;
	std::cout << "a || b &|| c: " << (a || b || c) << std::endl;

	// NOT: Negates whatever operand you put with
	std::cout << std::endl;
	std::cout << "Examples of NOT operations:" << std::endl;

	// we can use ! or not interchangeably
	std::cout << "!a: " << (!a) << std::endl;
	std::cout << "!b: " << (!b) << std::endl;
	std::cout << "not c: " << (not c) << std::endl;

	// combination all of these operators
	std::cout << std::endl;
	std::cout << "Combining logical operators:" << std::endl;
	std::cout << "!(a && b) || c: " << (not(a && b) || c) << std::endl;

	// combine logical with relational operators
	int d{ 45 };
	int e{ 20 };
	int f{ 11 };

	std::cout << std::endl;
	std::cout << "Relational and logic operations on integers" << std::endl;
	std::cout << "d : " << d << std::endl;
	std::cout << "e : " << e << std::endl;
	std::cout << "f : " << f << std::endl;

	std::cout << std::endl;

	std::cout << "(d > e) && (d > f) : " << ((d > e) && (d > f)) << std::endl; // true
	std::cout << "(d==e) || (e <= f ) : " << ((d == e) || (e <= f)) << std::endl;
	std::cout << "(d < e) || (d > f) : " << ((d < e) || (d > f)) << std::endl;
	std::cout << "(f > e) || (d < f) : " << ((f > e) || (d < f)) << std::endl;
	std::cout << "(d > f) && (f <= d) : " << ((d > f) && (f <= d)) << std::endl;
	std::cout << "(d > e) && (d <= f) : " << ((d > e) && (d <= f)) << std::endl;
	std::cout << "(! a) && (d == e) : " << ((!a) && (d == e)) << std::endl;
	std::cout << "(! a) && (d == e) : " << ((!a) && (d == e)) << std::endl;

	return 0;
}