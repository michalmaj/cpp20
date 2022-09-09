/*
 * If statement let us to do things under some condition.
 */

#include <iostream>


int main()
{

	int number1{ 55 };
	int number2{ 60 };

	bool result = (number1 < number2); // Expression yielding the condition
	std::cout << std::boolalpha << "result: " << result << std::endl;

	std::cout << std::endl;
	std::cout << "Free standing if statement" << std::endl;
	// Using two if statements
	if (result == true)
		std::cout << number1 << " is less than " << number2 << std::endl;

	if (!(result == true))
		std::cout << number1 << " is NOT less than " << number2 << std::endl;

	std::cout << std::endl;
	std::cout << "Using the else clause" << std::endl;
	// Using if else statement
	if (result == true)
		std::cout << number1 << " is less than " << number2 << std::endl;
	else
		std::cout << number1 << " is NOT less than " << number2 << std::endl;

	std::cout << std::endl;
	std::cout << "Using expression as condition" << std::endl;
	// Use expression as condition directly
	if (number1 < number2)
		std::cout << number1 << " is less than " << number2 << std::endl;
	else
		std::cout << number1 << " is NOT less than " << number2 << std::endl;


	std::cout << std::endl;
	std::cout << "Nesting if statements" << std::endl;

	// We can nest if statements
	bool red{ false };
	bool green{ true };
	bool yellow{ false };
	bool police_stop{ true };

	/*
	 *		If green: go
	 *		If red or yellow: stop
	 *		If green and police_Stop: stop
	 */

	if (red)
		std::cout << "Stop" << std::endl;
	if(yellow)
		std::cout << "Stop" << std::endl;
	if(green)
	{
		if(police_stop)
			std::cout << "Stop" << std::endl;
		else
			std::cout << "Go" << std::endl;
	}

	return 0;
}