#include <iostream>


extern const double distance; // declaration

void print_distance()
{
	std::cout << "distance(some_other_file): " << distance << std::endl;
	std::cout << "&distance(some_other_file): " << &distance << std::endl;
}


// Without static keyword it has an external linkage
static void some_other_function()
{
	std::cout << "Hello there\n";
}

namespace
{
	void some_function()
	{
		std::cout << "Hello there\n";
	}
}
