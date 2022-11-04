/*
 * A pointer or reference is said to be dangling if it's pointing
 * to or referencing invalid data. A simple example for pointers
 * is a pointer pointing to a deleted piece of memory.
 */

#include "dog.h"

int main()
{
	Dog dog1{ "Fluffy", "Shepherd", 2 };

	// Dangling reference
	//const std::string& str_ref = dog1.complie_dog_info();
	//std::cout << "info: " << str_ref << std::endl;

	// Dangling pointers
	/*unsigned int* int_ptr = dog1.jumps_per_minute();
	std::cout << "jumps: " << *int_ptr << std::endl;*/

	return 0;
}