#include "person.h"
#include "dog.h"

void do_something_with_dog_v1(std::unique_ptr<Dog> d)
{
	d->print_dog();
}

void do_something_with_dog_v2(const std::unique_ptr<Dog>& d)
{
	d->set_dog_name("Fluffy"); // we can set a new name, because a pointer is const not a dog
	d->print_dog();	
	//d.reset(); // Can't reset const std::unique_ptr
}

// return std::unique_ptr from function
std::unique_ptr<Dog> get_unique_ptr()
{
	std::unique_ptr<Dog> p_dog = std::make_unique<Dog>("Local Dog");
	std::cout << "std::unique_ptr address(in function): " << &p_dog << std::endl;

	return p_dog; // The compiler  does some optimizations and doesn't return a copy here.
				  // It's returning something like a reference  to the local object.
				  // We can prove this by looking at the address of objects in memory.
				  // This is not standard behavior, some compilers may actually return
				  // by value by making a copy. The compilers have some freedom to choose
				  // their own way to do things.
}

int main()
{
	// Passing std::unique_ptr to function by value
	std::unique_ptr<Dog> p_dog1 = std::make_unique<Dog>("Dog1");

	// Can't pass std::unique_ptr by value to a function: copies not allowed
	//do_something_with_dog_v1(p_dog1); // Compiler Error: copy detected

	// But it's possible to move ownership
	do_something_with_dog_v1(std::move(p_dog1)); // Ownership will move to the body
												 // of the function and memory will be
												 // released when function returns.
												 // Not what we typically want!

	std::cout << "p_dog1: " << p_dog1.get() << std::endl;
	std::cout << "Hitting the main function!\n";

	std::cout << "\n===================================\n\n";

	p_dog1 = std::make_unique<Dog>("Dog1"); // Give p_dog1 a new dog

	Person person1{ "John" };
	person1.adopt_dog(std::move(p_dog1)); // The same behavior when function is part of the class
	std::cout << "Doing something, p_dog1 points to: " << p_dog1.get() << std::endl; // p_dog1 again points to nullptr

	std::cout << "\n===================================\n\n";

	// An implicit move is done when object is created in place as a temporary
	do_something_with_dog_v1(std::make_unique<Dog>("Temporary Dog"));

	std::cout << "\n===================================\n\n";

	// Can pass the std::unique_ptr parameter by reference
	std::unique_ptr<Dog> p_dog2 = std::make_unique<Dog>("Dog2");
	p_dog2->print_dog();
	do_something_with_dog_v2(p_dog2);
	p_dog2->print_dog();

	std::cout << "\n===================================\n\n";

	std::unique_ptr<Dog> p_dog3 = get_unique_ptr();
	std::cout << "std::unique_ptr address(in main): " << &p_dog3 << std::endl;

	p_dog3->print_dog();

	return 0;
}