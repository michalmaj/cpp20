#include <iostream>

// internal linkage -> linkage
extern const double distance{ 45.7 };

void print_distance(); // Declaration

void some_other_function(); // Declaration

void some_function(); // Declaration

int main()
{
	std::cout << "distance(main): " << distance << std::endl;
	std::cout << "&distance(main): " << &distance << std::endl;

	std::cout << std::endl;

	print_distance();

	std::cout << "\n=================================\n" << std::endl;

	//// Not reachable from this place
	//some_other_function(); // For now this function has internal linkage
	//some_function(); // This function is wrapped around anonymous namespece in other translation unit 

	return 0;
}