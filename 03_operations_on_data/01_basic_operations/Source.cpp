/*
 * We can do basic math operations on variables.
 * We have addition, subtraction, multiplication and division.
 * If we divide integer by integer our result will be integer as well.
 * So, we get a quotient.
 * If we want a remainder from integer division we need to use modulus %.
 */

#include <iostream>


int main()
{
	// example of 
	int num1{ 2 };
	int num2{ 7 };

	int res = num1 + num2;
	std::cout << "addition: " << res << std::endl;

	// subtraction
	res = num1 - num2;
	std::cout << "subtraction: " << res << std::endl;

	// multiplication
	res = num1 * num2;
	std::cout << "multiplication: " << res << std::endl;

	// division
	res = num2 / num1;
	std::cout << "division: " << res << std::endl;

	// modulus
	res = num2 % num1;
	std::cout << "modulus: " << res << std::endl;


	return 0;
}