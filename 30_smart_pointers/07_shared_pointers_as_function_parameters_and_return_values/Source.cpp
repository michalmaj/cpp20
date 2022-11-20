#include <iostream>
#include <memory>
#include "dog.h"

// Passing by value
void use_dog_v1(std::shared_ptr<Dog> dog)
{
	std::cout << "shared_ptr passed by value, dog_name: " << dog->get_name() << std::endl;
	std::cout << "use count in use_dog_v1: " << dog.use_count() << std::endl;
}

// Passing by non-const reference
void use_dog_v2(std::shared_ptr<Dog>& dog)
{
	// Since no copy is made, we won't see the reference count increment here
	dog->set_dog_name("Sherpa");

	dog.reset(new Dog()); // Will reset, because passed by non-const reference

	std::cout << "shared_ptr passed by non-const reference, (dog name changed in function), dog_name: "
		<< dog->get_name() << std::endl;
	std::cout << "use count in use_dog_v2: " << dog.use_count() << std::endl;
}

// Passing by const reference
void use_dog_v3(const std::shared_ptr<Dog>& dog)
{
	// Since no copy is made, we won't see the reference count increment here
	dog->set_dog_name("Sherpa"); // We can change the dog object even though shared_ptr is passed
								 // by reference. The const protects the shared_ptr object itself,
								 // not the pointed to object.

	//dog.reset(new Dog()); // Compiler Error: passed by const reference

	std::cout << "shared_ptr passed by non-const reference, (dog name changed in function), dog_name: "
		<< dog->get_name() << std::endl;
	std::cout << "use count in use_dog_v2: " << dog.use_count() << std::endl;
}

// Returning by value
// Returning a shared_ptr by value goes through return value optimization and at the end no copy
// is made, we have a single shared ptr with a reference count of 1, just like we create a
//  shared directly with make_shared
std::shared_ptr<Dog> get_shared_ptr_v1()
{
	std::shared_ptr<Dog> dog_ptr = std::make_shared<Dog>("Internal Dog_v1");
	std::cout << "Managed dog address(in): " << dog_ptr.get() << std::endl;

	return dog_ptr;
}

// RETURNING SHARED_PTR BE REFERENCE (CONST OR NON-CONST) IS A RECIPE FOR DISASTER - VERY BAD!
// returning std::shared_ptr by reference doesn't properly increment the reference count,
// which opens up the risk of deleting something at he wrong time. We'll get a crash
std::shared_ptr<Dog>& get_shared_ptr_v2()
{
	std::shared_ptr<Dog> dog_ptr = std::make_shared<Dog>("Internal Dog_v2");

	return dog_ptr;
}


int main()
{
	// Passing by value: a copy will be made, increment the ref count in function body
	std::cout << std::endl;
	std::cout << "Passing shared_ptr by value\n";

	std::shared_ptr<Dog> shared_ptr_dog_1 = std::make_shared<Dog>("Filld");

	std::cout << "shared_ptr_dog_1 use count (before) : " << shared_ptr_dog_1.use_count() << std::endl;
	use_dog_v1(shared_ptr_dog_1);
	std::cout << "shared_ptr_dog_1 use count (after) : " << shared_ptr_dog_1.use_count() << std::endl;

	std::cout << "\n===========================================\n\n";

	std::cout << "Passing by non-const reference:\n";
	std::shared_ptr<Dog> shared_ptr_dog_2 = std::make_shared<Dog>("Flizy");

	std::cout << "shared_ptr_dog_2 use count (before) : " << shared_ptr_dog_2.use_count() << std::endl;
	use_dog_v2(shared_ptr_dog_2);
	std::cout << "shared_ptr_dog_2 use count (after) : " << shared_ptr_dog_2.use_count() << std::endl;

	std::cout << "\n===========================================\n\n";

	std::cout << "Passing by const reference:\n";
	std::shared_ptr<Dog> shared_ptr_dog_3 = std::make_shared<Dog>("Kitzo");

	std::cout << "shared_ptr_dog_3 use count (before) : " << shared_ptr_dog_3.use_count() << std::endl;
	use_dog_v3(shared_ptr_dog_3);
	std::cout << "shared_ptr_dog_3 use count (after) : " << shared_ptr_dog_3.use_count() << std::endl;

	std::cout << "\n===========================================\n\n";

	// Returning by value:
	// Returning a shared_ptr by value goes through return value optimization and the
	// end no copy is made, we have a single shared_ptr with reference count of 1
	// like when we create a shared directly with make_shared
	std::shared_ptr<Dog> shared_ptr_dog_4 = get_shared_ptr_v1();
	std::cout << "Managed dog address(in): " << shared_ptr_dog_4.get() << std::endl;
	std::cout << "shared_ptr_dog_4 use count: " << shared_ptr_dog_4.use_count() << std::endl;

	std::cout << "\n===========================================\n\n";

	//// Returning by reference: don't do this
	//std::shared_ptr<Dog> shared_ptr_dog_5 = get_shared_ptr_v2();
	//std::cout << "shared_ptr_dog_5 use count: " << shared_ptr_dog_5.use_count() << std::endl;
	//shared_ptr_dog_5->print_dog();

	//std::cout << "\n===========================================\n\n";

	return 0;
}