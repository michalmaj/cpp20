#include "dog.h"

// This causes no problem because we are working with
// a copy inside the function
void function_taking_dog(Dog dog)
{
	dog.set_name("Internal Dog");
	dog.print_info();
}

// Parameter by reference
void function_taking_dog_ref(Dog& dog)
{
	// Compiler won't allow passing const object as an argument
	dog.set_name("Internal Dog");
	dog.print_info();
}

// Parameter by const reference
void function_taking_const_dog_ref(const Dog& dog)
{
	// Can't modify const Dog reference
	// dog.set_name("Internal Dog"); // Compiler Error - expected
	dog.print_info(); // Now works!
}

// Pointer to non-const as a parameter
void function_taking_dog_ptr(Dog* dog)
{
	// Compiler won't allow passing const object as an argument
	dog->set_name("Internal Dog");
	dog->print_info();
}

// Pointer to const as a parameter
void function_taking_const_dog_ptr(const Dog* dog)
{
	// Can't modify const Dog pointer
	// dog->set_name("Internal Dog"); // Compiler Error - expected
	dog->print_info(); // Now works!
}

int main()
{
	const Dog dog1{ "Fluffy", "Shepherd", 2 };
	dog1.print_info();

	// Function taking parameter by value: WORKS
	function_taking_dog(dog1);

	//// Function taking parameters by reference: DOESN'T WORK
	//function_taking_dog_ref(dog1); // Compiler Error

	//Function taking parameters by const reference : WORKS
	function_taking_const_dog_ref(dog1);

	//// Function taking parameters by pointer: DOESN'T WORK
	//function_taking_dog_ptr(&dog1);

	////Function taking parameters by pointer to const: WORKS
	function_taking_const_dog_ptr(&dog1);

	return 0;
}