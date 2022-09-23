/*
 * Heap memory:
 *  - the developer is in full control of when memory is allocated and when it's released
 *	- lifetime is controlled explicitly through new and delete operators
 */

#include <iostream>

int main()
{

	// How we've used pointers so far
	int number{ 22 }; // Stack memory

	int* p_number = &number;

	std::cout << std::endl;
	std::cout << "Declaring pointer and assigning address:" << std::endl;
	std::cout << "number: " << number << std::endl;
	std::cout << "p_number: " << p_number << std::endl;
	std::cout << "&number: " << &number << std::endl;
	std::cout << "*p_number: " << *p_number << std::endl;


	int* p_number1; // Uninitialized pointer, contains junk address
	int number1{ 12 };
	p_number1 = &number1; // Make it point to a valid address
	std::cout << std::endl;
	std::cout << "Uninitialized pointer:" << std::endl;
	std::cout << "*p_number1: " << *p_number1 << std::endl;

	std::cout << "\n==============================================\n\n";

	//// BAD CODE!!!!!
	//// Writing into uninitialized pointer through dereference
	//int* p_number2; // Contains junk address: could be anything
	//*p_number2 = 55; // Writing into junk address: BAD!, compiler error at msvc
	//std::cout << std::endl;
	//std::cout << "Writing into uninitialized pointer through dereference" << std::endl;
	//std::cout << "p_number2 : " << p_number2 << std::endl; // Reading from junk address.
	//std::cout << "Dereferencing bad memory" << std::endl;
	//std::cout << "*p_number2 : " << *p_number2 << std::endl;

	// Initializing pointer to nullptr
	int* p_number3{}; // Initialized with pointer equivalent of zero: nullptr
					  // A pointer pointing nowhere
	//*p_number3 = 33; // Writing into pointer pointing nowhere: BAD, CRASH 
	std::cout << std::endl;
	std::cout << "Reading and writing through nullptr:" << std::endl;
	std::cout << "p_number3: " << p_number3 << std::endl;
	//std::cout << "*p_number3: " << *p_number3 << std::endl; // Reading from nullptr
	//														// BAD, CRASH

	std::cout << "\n==============================================\n\n";

	// Dynamic heap memory
	int* p_number4{ nullptr };
	p_number4 = new int; // Dynamically allocate space for a single int on the heap.
						 // This memory belongs to our program from now on. The system
						 // can't use it for anything else, until we return it.
						 // After this line executes, we will have a valid memory location
						 // allocated. The size of the allocated memory will be such that it
						 // can store the type pointed to by the pointer.

	*p_number4 = 77; // Writing into dynamically allocated memory
	std::cout << std::endl;
	std::cout << "Dynamically allocated memory:" << std::endl;
	std::cout << "*p_number4: " << *p_number4 << std::endl;

	delete p_number4;
	p_number4 = nullptr;

	std::cout << "\n==============================================\n\n";

	// It is also possible to initialize the pointer with a valid
	// address up on declaration. Not with nullptr
	int* p_number5{ new int }; // Memory location contains junk value
	int* p_number6{ new int(22) }; // Use direct information
	int* p_number7{ new int{23} }; // Use uniform initialization

	std::cout << std::endl;
	std::cout << "Initialize with valid memory address at declaration : " << std::endl;
	std::cout << "p_number5 : " << p_number5 << std::endl;
	std::cout << "*p_number5 : " << *p_number5 << std::endl; // Junk value

	std::cout << "p_number6 : " << p_number6 << std::endl;
	std::cout << "*p_number6 : " << *p_number6 << std::endl;

	std::cout << "p_number7 : " << p_number7 << std::endl;
	std::cout << "*p_number7 : " << *p_number7 << std::endl;

	//Remember to release the memory
	delete p_number5;
	p_number5 = nullptr;

	delete p_number6;
	p_number6 = nullptr;

	delete p_number7;
	p_number7 = nullptr;

	std::cout << "\n==============================================\n\n";

	// Can reuse pointers
	p_number5 = new int(81);
	std::cout << "*p_number5 : " << *p_number5 << std::endl;

	delete p_number5;
	p_number5 = nullptr;

	std::cout << "\n==============================================\n\n";

	// Calling delete operator twice on a pointer: BAD!
	p_number5 = new int(99);
	std::cout << "*p_number5 : " << *p_number5 << std::endl;

	delete p_number5;
	//delete p_number5; // CRASH
	p_number5 = nullptr;


	return 0;
}