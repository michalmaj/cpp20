#include "dog.h"

int main()
{
	Dog dog1{ "Fluffy", "Shepherd", 2 };

	std::cout << dog1.name() << std::endl; // Function works as a getter

	// Modify the object
	dog1.name() = "Millie"; // Function works as a setter
	std::cout << dog1.name() << std::endl;

	const Dog dog2{ "Sherpa", "Malamute", 12 };
	std::cout << dog2.name() << std::endl; // Works, because we created an overload const function

	//// But we can't modify const object
	//dog2.name() = "Millie"; // Compiler Error

	return 0;
}