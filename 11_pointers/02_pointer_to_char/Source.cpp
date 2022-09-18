#include <iostream>

int main()
{
	const char* message{ "Hello World!" }; // Can't compile without make it const

	std::cout << "message: " << message << std::endl;

	// Pointer pointing to first element, so dereferencing shows us letter 'H'
	std::cout << "*message: " << *message << std::endl;

	std::cout << "\n=============================================\n\n";

	//*message = 'B'; // Compiler Error

	// Allow users to modify the string
	char message1[]{ "Hello World!" };
	message1[0] = 'B';
	std::cout << "message1: " << message1 << std::endl;



	return 0;
}