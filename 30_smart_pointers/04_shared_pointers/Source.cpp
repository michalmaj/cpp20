#include <iostream>
#include <memory>
#include "dog.h"

int main()
{
	// shared pointers to fundamental type
	{
		std::shared_ptr<int> int_ptr1{ new int{20} };

		std::cout << "The pointed to vale is: " << *int_ptr1 << std::endl;
		*int_ptr1 = 40; // use the pointer to assign
		std::cout << "The pointed to value is: " << *int_ptr1 << std::endl;
		std::cout << "Use count: " << int_ptr1.use_count() << std::endl;

		std::cout << "-----------------------------" << std::endl;

		// Copying
		std::shared_ptr<int> int_ptr2 = int_ptr1; // Use count 2
		std::cout << "The pointed to vale is (through int_ptr2): " << *int_ptr2 << std::endl;
		*int_ptr2 = 70;
		std::cout << "The pointed to vale is (through int_ptr2): " << *int_ptr2 << std::endl;
		std::cout << "The pointed to vale is (through int_ptr1): " << *int_ptr1 << std::endl;

		std::cout << "Use count: " << int_ptr1.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr2.use_count() << std::endl;


		std::cout << "-----------------------------" << std::endl;

		// Other ways to initialize shared pointers
		std::shared_ptr<int> int_ptr3; // nullptr
		int_ptr3 = int_ptr1; // Use count 3

		std::shared_ptr<int> int_ptr4{ nullptr };
		int_ptr4 = int_ptr1; // Use count 4

		std::shared_ptr<int> int_ptr5{ int_ptr1 }; // Use count 5
		std::cout << "The pointed to vale is (through int_ptr5): " << *int_ptr5 << std::endl;
		*int_ptr5 = 100;

		std::cout << "Use count: " << int_ptr1.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr2.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr3.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr4.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr5.use_count() << std::endl;

		std::cout << "-----------------------------" << std::endl;

		// Reset: decrements the use count and sets the pointer to nullptr
		int_ptr5.reset(); // decrement reference count and sets int_ptr5 to nullptr
		std::cout << "int_ptr5.get(): " << int_ptr5 << std::endl; // nullptr

		// After this use count for int_ptr5 will be 0 and rest decrements by 1
		std::cout << "Use count: " << int_ptr1.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr2.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr3.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr4.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr5.use_count() << std::endl;

		std::cout << "-----------------------------" << std::endl;

		// Use a shared pointer to manage an already existing piece of memory
		int* int_ptr_raw = new int{ 33 };

		std::shared_ptr<int> int_ptr6{ int_ptr_raw };

		std::cout << "The pointed to vale is (through int_ptr6): " << *int_ptr6 << std::endl;
		std::cout << "Use count: " << int_ptr6.use_count() << std::endl;

		std::cout << "Raw pointer: " << int_ptr_raw << std::endl; // Raw pointer still pointing to same address
		std::cout << "int_ptr6.get(): " << int_ptr6.get() << std::endl; // int_ptr6 points to the same address

		// We need to set raw pointer to nullptr
		int_ptr_raw = nullptr;

		std::cout << "-----------------------------" << std::endl;

		// Can get the raw pointer address and use the ptr in if statements (castable to bool)
		std::cout << "int_ptr4: " << *int_ptr4 << std::endl;
		std::cout << "int_ptr4.get(): " << int_ptr4.get() << std::endl;
		std::cout << std::boolalpha;
		std::cout << "int_ptr4->bool: " << static_cast<bool>(int_ptr4) << std::endl;
		std::cout << "int_ptr5->bool: " << static_cast<bool>(int_ptr5) << std::endl;

		if (int_ptr4)
			std::cout << "int_ptr4 points to something valid\n";
		else
			std::cout << "int_ptr4 points to nullptr valid\n";

		int_ptr4.reset();
		std::cout << "Use count: " << int_ptr1.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr2.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr3.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr4.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr5.use_count() << std::endl;

		if (int_ptr4)
			std::cout << "int_ptr4 points to something valid\n";
		else
			std::cout << "int_ptr4 points to nullptr valid\n";

		// reset all pointers
		int_ptr3.reset();
		int_ptr2.reset();
		int_ptr1.reset();
		std::cout << "Use count: " << int_ptr1.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr2.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr3.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr4.use_count() << std::endl;
		std::cout << "Use count: " << int_ptr5.use_count() << std::endl;
 	}

	// Shared pointers with custom types
	{
		std::shared_ptr<Dog> dog_ptr1{ new Dog{"Dog1"} };
		dog_ptr1->print_dog();

		std::cout << "use count: " << dog_ptr1.use_count() << std::endl; // 1

		std::shared_ptr<Dog> dog_ptr2 = dog_ptr1; // use count 2
		std::cout << "use count for dog_ptr1: " << dog_ptr1.use_count() << std::endl;
		std::cout << "use count for dog_ptr2: " << dog_ptr2.use_count() << std::endl;

		std::shared_ptr<Dog> dog_ptr3;
		dog_ptr3 = dog_ptr1; // Use count : 3
		std::shared_ptr<Dog> dog_ptr4{ nullptr };
		dog_ptr4 = dog_ptr1; // Use count : 4

		std::shared_ptr<Dog> dog_ptr5{ dog_ptr1 }; // Use count : 5

		std::cout << std::endl;
		std::cout << "Use count for dog_ptr1: " << dog_ptr1.use_count() << std::endl;
		std::cout << "Use count for dog_ptr2: " << dog_ptr2.use_count() << std::endl;
		std::cout << "Use count for dog_ptr3: " << dog_ptr3.use_count() << std::endl;
		std::cout << "Use count for dog_ptr4: " << dog_ptr4.use_count() << std::endl;
		std::cout << "Use count for dog_ptr5: " << dog_ptr5.use_count() << std::endl;

		// can also initialize from an already existing raw pointer
		Dog* dog_ptr_raw = new Dog{ "Ralso" };

		std::shared_ptr<Dog> dog_ptr6{ dog_ptr_raw };
		dog_ptr_raw = nullptr; // remember to reset raw pointer to nullptr
		dog_ptr6->print_dog();
		std::cout << "Use count for dog_ptr6: " << dog_ptr6.use_count() << std::endl;

		dog_ptr5.reset(); // decrements reference count and sets int_ptr5 to nullptr
		// after this if you show use count, for int_ptr5,you'll get 0
		std::cout << "Use count for dog_ptr1 : " << dog_ptr1.use_count() << std::endl;
		std::cout << "Use count for dog_ptr2 : " << dog_ptr2.use_count() << std::endl;
		std::cout << "Use count for dog_ptr3 : " << dog_ptr3.use_count() << std::endl;
		std::cout << "Use count for dog_ptr4 : " << dog_ptr4.use_count() << std::endl;
		std::cout << "Use count for dog_ptr5 : " << dog_ptr5.use_count() << std::endl;


		//Can get the raw pointer address and use the ptr in if statements
		std::cout << std::endl;
		std::cout << "Casting to bool and using in if statements..." << std::endl;
		std::cout << "dog_ptr4 : " << dog_ptr4 << std::endl;
		std::cout << "dog_ptr4.get() : " << dog_ptr4.get() << std::endl;
		std::cout << "dog_ptr4->bool : " << static_cast<bool>(dog_ptr4) << std::endl;
		std::cout << "dog_ptr5->bool : " << static_cast<bool>(dog_ptr5) << std::endl;

		if (dog_ptr5) {
			std::cout << "dog_ptr5 pointing to something valid" << std::endl;
		}
		else {
			std::cout << "dog_ptr5 pointing to nullptr" << std::endl;
		}
	}

	// make_shared
	{
		std::shared_ptr<int> int_ptr6 = std::make_shared<int>(55);
		std::cout << "the value pointet by int_ptr6 is: " << *int_ptr6 << std::endl;

		std::shared_ptr<Dog> dog_ptr6 = std::make_shared<Dog>("Salz");
		dog_ptr6->print_dog();
		std::cout << "Use count for int_ptr6 : " << int_ptr6.use_count() << std::endl;
		std::cout << "Use count for dog_ptr6 : " << dog_ptr6.use_count() << std::endl;

		std::cout << std::endl;
		std::cout << "Share the object(data) with other shared_ptr's" << std::endl;
		std::shared_ptr<int> int_ptr7{ nullptr };
		int_ptr7 = int_ptr6;

		std::shared_ptr<Dog> dog_ptr7{ nullptr };
		dog_ptr7 = dog_ptr6;

		std::cout << "int_ptr6 use count : " << int_ptr6.use_count() << std::endl;
		std::cout << "dog_ptr6 use count : " << dog_ptr6.use_count() << std::endl;


		std::cout << std::endl;
		std::cout << "Reset ptr6's" << std::endl;
		int_ptr6.reset(); // decrement reference count, and set int_ptr6 to nullptr
		// if reference count is zero, release the managed memory
		dog_ptr6.reset();
		std::cout << "int_ptr_6 use count : " << int_ptr6.use_count() << std::endl;
		std::cout << "dog_ptr_6 use count : " << dog_ptr6.use_count() << std::endl;
		std::cout << "int_ptr_7 use count : " << int_ptr7.use_count() << std::endl;
		std::cout << "dog_ptr_7 use count : " << dog_ptr7.use_count() << std::endl;
	}
}