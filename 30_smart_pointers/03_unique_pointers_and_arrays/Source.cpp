#include <iostream>
#include <memory>
#include "dog.h"


int main()
{

	// Array allocated on the stack
	{
		std::cout << "Working with dog array on the stack\n";
		Dog dog_array[3]{ Dog{"Dog1"}, Dog{"Dog2"}, Dog{"Dog3"} };
		for(size_t i{0}; i < std::size(dog_array); ++i)
		{
			dog_array[i].print_dog();
		}
	}
	std::cout << "Done!\n";

	std::cout << "\n===============================\n\n";

	// Array allocated on the heap
	{
		std::cout << "Working with array allocated on the heap.\n";
		Dog* p_dog_array_raw = new Dog[3]{ Dog{"Dog4"}, Dog{"Dog5"}, Dog{"Dog6"} };
		for(size_t i{0}; i < 3; ++i)
		{
			p_dog_array_raw[i].print_dog();
		}

		// If we don't delete explicitly (like below). The memory for the array won't be released and
		// we won't see the destructors for Dog 4~~6 called. If we delete explicitly, everything goes
		// as expected and the destructors are called when we exit this scope.
		delete[] p_dog_array_raw;
	}
	std::cout << "Done!\n";

	std::cout << "\n===============================\n\n";

	// Array allocated on the heap with unique_ptr. Releases space for array automatically
	{
		std::cout << "Array on heap with std:unique_ptr.\n";

		auto arr_ptr = std::unique_ptr<Dog[]>{ new Dog[3]{Dog{"Dog7"}, Dog{"Dog8"}, Dog{"Dog9"}} };

		//auto arr_ptr = std::make_unique<Dog[]>(3);// Works. Can't initialize individual elements
		//auto arr_ptr = std::make_unique<Dog[]>(3) {Dog("Dog7"), Dog("Dog8") , Dog("Dog9")};//Compiler error
		//auto arr_ptr = std::make_unique<Dog[]>{Dog("Dog7"), Dog("Dog8") , Dog("Dog9")};//Compiler error
		for(int i{0}; i < 3; ++i)
		{
			arr_ptr[i].print_dog();
		}

	}


	return 0;
}