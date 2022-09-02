/*
 * A relational operator is used to check the relationship between two operands (variables).
 *
 * == Operator
 * The equal to == operator returns:
 *		true - if both the operands are equal or the same
 *		false - if the operands are unequal
 *
 * != Operator
 * The not equal to != operator returns:
 *		true - if both operands are unequal
 *		false - if both operands are equal.
 *
 * > Operator
 * The greater than > operator returns
 *		true - if the left operand is greater than the right
 *		false - if the left operand is less than the right
 *
 * < Operator
 * The less than operator < returns:
 *		true - if the left operand is less than the right
 *		false - if the left operand is greater than right
 *
 * >= Operator
 * The greater than or equal to >= operator returns
 *		true - if the left operand is either greater than or equal to the right
 *		false - if the left operand is less than the right
 *
 * <= Operator
 * The less than or equal to operator <= returns
 *		true - if the left operand is either less than or equal to the right
 *		false - if the left operand is greater than right
 */

#include <iostream>


int main()
{
	int num1{ 45 };
	int num2{ 60 };

	std::cout << "num1: " << num1 << std::endl;
	std::cout << "num2: " << num2 << std::endl;

	// All these comparison operators evaluated to boolean.
	// So, we get true or false output

	std::cout << std::endl;
	std::cout << "Comparing two variables:" << std::endl;

	std::cout << std::boolalpha; // make bool to be in true/false instead of 1/0 form

	// Remember to put expression in parentheses.
	// Friendly remainder single equal sign = is a assignment operator.
	// To check if both values are equal we have to use == operator
	std::cout << "num1 == num2: " << (num1 == num2) << std::endl;
	std::cout << "num1 != num2: " << (num1 != num2) << std::endl;
	std::cout << "num1 > num2: " << (num1 > num2) << std::endl;
	std::cout << "num1 < num2: " << (num1 < num2) << std::endl;
	std::cout << "num1 >= num2: " << (num1 >= num2) << std::endl;
	std::cout << "num1 <= num2: " << (num1 <= num2) << std::endl;

	// we can store the comparison result in another variable
	std::cout << std::endl;
	std::cout << "Store comparison result in another variable:" << std::endl;

	bool result = (num1 == num2);

	std::cout << num1 << " == " << num2 << ": " << result << std::endl;


	return 0;
}