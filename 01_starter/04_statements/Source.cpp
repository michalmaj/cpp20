/*
 * Basic unit of computation in C++ is a statement.
 * Every C++ program is a collection of statements.
 * Statements in C++ ended with a semicolon (;).
 * Statements are executed in order from top to bottom when the program runs.
 * Execution keeps going until is a statement causing the termination, or
 * run another sequence of statements.
 */

// We can also use a function.
// Function is a block of code in curly braces {}.
// Function let's us reuse code many times.
// Function consists of the:
// return type, name, list of parameters
int add_numbers(int first_param, int second_param)
{
	int sum = first_param + second_param;
	return sum;
}

// Function sums two integers
// Our new function below let's us multiply two variables
int multiply_numbers(int first_param, int second_param)
{
	int multiply = first_param * second_param;
	return multiply;
}

#include <iostream>

int main()
{
	// Creating a variable is a statement
	int first_number = 1; // This is a statement
	int second_number = 2; // This is also a statement

	int sum = first_number + second_number;

	std::cout << "Our sum: " << sum << std::endl;

	// Using function for calculations
	int num1 = 98;
	int num2 = 74;
	int result = add_numbers(num1, num2);
	std::cout << "Our result (addition): " << result << std::endl;

	// We can reuse our function
	result = add_numbers(10, 19);
	std::cout << "Our result (addition): " << result << std::endl;

	// We can also call function directly in std::cout
	std::cout << "Our result (addition): " << add_numbers(84, 14) << std::endl;

	// we can reuse our result variable, because both functions return integers
	result = multiply_numbers(13, 4);
	std::cout << "Our result (multiplication): " << result << std::endl;

	return 0;
}