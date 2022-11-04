#include "dog.h"


int main()
{
	Dog dog1{ "Fluffy", "Shepherd", 2 };
	dog1.print_info();

	dog1.set_name("Millie");
	dog1.print_info();


	// We can create also a const object - direct access
	const Dog dog2{ "Sherpa", "Malamute", 12 };
	//dog2.print_info(); // Compiler Error if this method is not marked as const

	//dog2.set_name("Millie"); // Compiler Error, we can't modify a const object

	//// Pointer to non-const
	//Dog* dog_ptr{ &dog2 }; // Compiler Error - cannot convert from const Dog* to Dog*

	//// Non-const reference
	//Dog& dog_ref = dog2; // Compiler Error - cannot convert from const Dog to Dog&

	// Pointer to const
	const Dog* const_dog_ptr{ &dog2 };
	//const_dog_ptr->set_name("Millie"); // Compiler Error

	// Const reference
	const Dog& const_dog_ref = dog1;
	//const_dog_ref.set_name("Millie"); // Compiler Error


	return 0;
}