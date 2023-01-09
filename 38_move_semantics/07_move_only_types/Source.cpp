#include "boxcontainer.h"
#include <memory>

void populate_box(BoxContainer<int>& box, int modifier)
{
	for (size_t i{ 0 }; i < 20; ++i)
		box.add((i + 1) * modifier);
}



int main()
{
	BoxContainer<int> box1;
	populate_box(box1, 2);


	std::cout << "box1: " << box1 << std::endl;


	std::cout << "----------------------------" << std::endl;

	//BoxContainer<int> box2{ box1 }; // Can't use it, because copy constructor is deleted

	BoxContainer<int> box3;

	//box3 = box1; // Can't use it copy assignment is deleted

	box3 = std::move(box1); // Works - move assignment is available 
	std::cout << "box3: " << box3 << std::endl;
	std::cout << "box1: " << box1 << std::endl;

	std::cout << "----------------------------" << std::endl;

	std::unique_ptr<int> ptr_int = std::make_unique<int>(33);
	std::cout << "*ptr_int: " << *ptr_int << std::endl;

	//std::unique_ptr<int> ptr_int_copy = ptr_int; // Unique pointer can't cont on another unique pointer instance

	std::unique_ptr<int> ptr_int_move = std::move(ptr_int); // But we can steal from unique pointer, it is move an ownership of ptr_int
	std::cout << "*ptr_int_move: " << *ptr_int_move << std::endl;
	if(ptr_int)
		std::cout << "*ptr_int: " << *ptr_int << std::endl;
	else
		std::cout << "ptr_int doesn't contain any valid data" << std::endl;


	return 0;
}