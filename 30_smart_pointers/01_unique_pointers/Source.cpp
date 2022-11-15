/*
 * Unique pointers:
 *	- at any given  moment there can only be
 *	  one pointer managing the memory
 *	- memory is automatically released when the
 *	  the pointer goes out of scope
 */

#include <iostream>
#include <memory>

#include "dog.h"


int main()
{
	// Stack variables (destroyed at the end of the current scope)
	Dog dog1{ "Dog1" }; // Will be destroyed at the end of main function
	// Calling functions on stack objects
	dog1.print_dog();

	{
		// Stack variables
		Dog dog1{ "Nested Dog" }; // Will be destroyed at the end oh this scope
		// Calling functions on stack objects
		dog1.print_dog();
	}
	std::cout << "Hitting outside the scope\n";

	std::cout << "\n============================================\n\n";

	// Using raw pointers: remember to manually release memory
	// if you don't release, you leak memory
	Dog* p_dog2 = new Dog("Dog2");
	int* p_int1 = new int(100);

	p_dog2->print_dog();
	std::cout << "Integer is: " << *p_int1 << std::endl;
	std::cout << "Integer lives at address: " << p_int1 << std::endl;

	// If you go out of scope without releasing (deleting)
	// p_dog2 and p_int1 you'll heave leaked memory
	delete p_dog2; // Calls the destructor
	p_dog2 = nullptr;
	delete p_int1;
	p_int1 = nullptr;

	std::cout << "\n============================================\n\n";

	// Using unique_ptr: managed memory is owned by a single pointer at any moment
	Dog* p_dog3 = new Dog{ "Dog3" };
	std::unique_ptr<Dog> up_dog4{ p_dog3 }; // Can also manage previously allocated
											// space managed by a raw pointer. We shouldn't
											// try to use the raw pointer from this point on.
	std::unique_ptr<Dog> up_dog5{ new Dog("Dog5") };
	std::unique_ptr<int> up_int2{ new int{200} };
	std::unique_ptr<Dog> up_dog6{ nullptr }; // Can also initialize with nullptr and give it memory
											 // to manage later, we'll see how to do that with
											 // std::move. Just know that we can initialize std::unique_ptr
											 // with nullptr.

	// Can use unique poinetr just like we use a raw pointer
	up_dog5->print_dog(); // Calling function with -> operator

	// Assign to fundamental type
	*up_int2 = 500;
	std::cout << "Integer is: " << *up_int2 << std::endl; // dereferencing
	std::cout << "Integer lives at address: " << up_int2.get() << std::endl;

	{
		Dog* p_dog3 = new Dog{ "UP Nested Dog1" };
		std::unique_ptr<Dog> up_dog4{ p_dog3 }; // Can also manage previously allocated
		// space managed by a raw pointer. We shouldn't
		// try to use the raw pointer from this point on.
		std::unique_ptr<Dog> up_dog5{ new Dog("UP Nested Dog2") };
		std::unique_ptr<int> up_int2{ new int{200} };
		std::unique_ptr<Dog> up_dog6{ nullptr }; // Can also initialize with nullptr and give it memory
		// to manage later, we'll see how to do that with
		// std::move. Just know that we can initialize std::unique_ptr
		// with nullptr.

		// Can use unique poinetr just like we use a raw pointer
		up_dog5->print_dog(); // Calling function with -> operator

		// Assign to fundamental type
		*up_int2 = 500;
		std::cout << "Integer is: " << *up_int2 << std::endl; // dereferencing
		std::cout << "Integer lives at address: " << up_int2.get() << std::endl;
	}
	std::cout << "Hitting outside the scope\n";

	std::cout << "\n============================================\n\n";

	// Using std::make_unique syntax to avoid using new operator. Much cleaner (since C++14)
	// Calls new internally for us, we don't have to do it ourselves
	std::unique_ptr<Dog> up_dog7 = std::make_unique<Dog>("Dog7");
	up_dog7->print_dog();

	std::unique_ptr<int> up_int3 = std::make_unique<int>(30);
	*up_int3 = 67;
	std::cout << "Value pointed by up_int3 is: " << *up_int3 << std::endl; // dereferencing
	std::cout << "up_int3 pointing at address: " << up_int3.get() << std::endl;

	std::cout << "\n============================================\n\n";

	// Copies not allowed
	std::unique_ptr<Dog> up_dog8 = std::make_unique<Dog>("Dog8");
	up_dog8->print_dog();
	// Can get the wrapped pointer address: useful for older raw pointer APIs
	std::cout << "Dog8 memory address: " << up_dog8.get() << std::endl;

	//// Copies and Assignments are not allowed with unique ptr
	//std::unique_ptr<Dog> up_dog9 = up_dog8; // Compiler Error. This also does some kind of copy
	//std::unique_ptr<Dog> up_dog10{ up_dog8 }; // Compiler Error: Copy constructor deleted

	std::cout << "\n============================================\n\n";

	// Can however move the pointer
	std::unique_ptr<Dog> up_dog11 = std::make_unique<Dog>("Dog11");
	{
		std::unique_ptr<Dog> up_dog12 = std::move(up_dog11); // Now up_dog12 manages Dog11 and
															 // up_dog11 points to nothing (nullptr)
		up_dog12->print_dog();
		std::cout << "DOg12 memory address: " << up_dog12.get() << std::endl;

		std::cout << "up_dog11 is now nullptr: " << up_dog11.get() << std::endl;
	}
	std::cout << "Hitting outside the scope\n";

	std::cout << "\n============================================\n\n";

	// Can reset unique_ptr: releases memory and sets the pointer to nullptr
	std::unique_ptr<Dog> up_dog13 = std::make_unique<Dog>("Dog13");
	up_dog13.reset(); // release memory and set pointer to nullptr

	// Can use unique_ptr in if statement to see if it points somewhere valid
	if (up_dog13)
		std::cout << "up_dog13 points somewhere valid: " << up_dog13.get() << std::endl;
	else
		std::cout << "up_dog13 is nullptr: " << up_dog13.get() << std::endl;

	std::cout << "Done!\n";
	return 0;
}