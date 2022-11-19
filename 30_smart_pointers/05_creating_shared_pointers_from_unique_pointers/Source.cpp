#include <iostream>
#include <memory>
#include "dog.h"

std::unique_ptr<Dog> get_unique_ptr()
{
	std::unique_ptr<Dog> dog_ptr_internal = std::make_unique<Dog>("Phil");
	return dog_ptr_internal;
}

int main()
{
	// Create shared pointers from unique_ptrs
	std::unique_ptr<int> unique_ptr_int_1 = std::make_unique<int>(22);
	std::unique_ptr<Dog> unique_ptr_dog_1 = std::make_unique<Dog>("Halz");

	// Create shared pointers from unique_ptrs
	// Ownership moves from unique_ptrs to shared_ptrs
	std::shared_ptr<int> shared_ptr_int_1 = std::move(unique_ptr_int_1);
	std::shared_ptr<Dog> shared_ptr_dog_1 = std::move(unique_ptr_dog_1);

	//std::shared_ptr<Dog> shared_ptr_dog_2 = unique_ptr_dog_1; // Compiler Error: direct assignment
	//														  // doesn't work, we have to do an
	//														  // std::move to move ownership

	std::cout << "shared_ptr_int_1 use count: " << shared_ptr_int_1.use_count() << std::endl; // 1
	std::cout << "shared_ptr_dog_1 use count: " << shared_ptr_dog_1.use_count() << std::endl; // 1

	std::cout << std::boolalpha;
	std::cout << "unique_ptr_int_1: " << static_cast<bool>(unique_ptr_int_1) << std::endl;
	std::cout << "unique_ptr_dog_1: " << static_cast<bool>(unique_ptr_dog_1) << std::endl;

	std::cout << "unique_ptr_int_1: " << unique_ptr_int_1 << std::endl;
	std::cout << "unique_dog_int_1: " << unique_ptr_dog_1 << std::endl;

	// We can create copies because now we hold a shared_ptr
	std::cout << std::endl;
	std::cout << "Making copies...\n";
	std::shared_ptr<int> shared_ptr_int_3{ shared_ptr_int_1 };
	std::shared_ptr<Dog> shared_ptr_dog_3{ shared_ptr_dog_1 };

	std::cout << "shared_ptr_int_1 use count: " << shared_ptr_int_1.use_count() << std::endl; // 2
	std::cout << "shared_ptr_dog_1 use count: " << shared_ptr_dog_1.use_count() << std::endl; // 2
	std::cout << "shared_ptr_int_3 use count: " << shared_ptr_int_3.use_count() << std::endl; // 2
	std::cout << "shared_ptr_dog_3 use count: " << shared_ptr_dog_3.use_count() << std::endl; // 2

	// Can't transform from std::shared_ptr to std::unique_ptr
	// The reason this transformation is disabled isn't hard to think of.
	// At any given moment, there may be any number of shared pointers
	// spread through our entire application working on the same object.
	// If you were to instantly make one of those a unique pointer, what do
	// you do with the remaining copies? Unique pointers can't have copies
	// anyway. So the compiler prevents you from doing this.
	//std::unique_ptr<int> unique_ptrq_illegel_1{ shared_ptr_int_3 }; // Compiler Error
	//std::unique_ptr<int> unique_ptrq_illegel_1 = shared_ptr_int_3 ; // Compiler Error
	//std::unique_ptr<int> unique_ptrq_illegel_1 = std::move(shared_ptr_int_3); // Compiler Error

	// Returning std::unique_ptr to unique_ptr
	std::cout << std::endl;
	std::cout << "Returning unique_ptr from function to unique_ptr\n";
	std::unique_ptr<Dog> unique_ptr_dog_2 = get_unique_ptr(); // This implicitly moves ownership

	if (unique_ptr_dog_2)
		std::cout << "unique_ptr_dog_2 dog name: " << unique_ptr_dog_2->get_name() << std::endl;

	// Returning unique_ptr to shared_ptr
	std::cout << std::endl;
	std::cout << "Returning unique_ptr from function to shared_ptr\n";
	std::shared_ptr<Dog> shared_ptr_dog_4 = get_unique_ptr(); // This implicitly moves ownership to shared_ptr_dog_4
															  // Implicitly does something like this:
															  // std_shared_ptr<Dog> shared_ptr_dog_1 = std::move(dog_ptr_internal)
															  // moving ownership to a shared pointer whose reference count becomes 1.

	if(shared_ptr_dog_4)
	{
		std::cout << "shared_ptr_dog_4 dog name: " << shared_ptr_dog_4->get_name() << std::endl;
		std::cout << "shared_ptr_dog_4 dog use count: " << shared_ptr_dog_4.use_count() << std::endl;
	}

	return 0;
}