#include <iostream>

inline int age{ 12 };

inline void some_function()
{
	std::cout << "age: " << age << std::endl;
	std::cout << "&age: " << &age << std::endl;
}

void print_age_2()
{
	std::cout << "Printing from utility1\n";
	some_function();
	std::cout << std::endl;
}

namespace
{
	double distance{ 23.9 };

	void some_distance_function()
	{
		std::cout << "distance: " << distance << std::endl;
		std::cout << "&distance: " << &distance << std::endl;
	}
}

void print_distance_2()
{
	std::cout << "distance(utility1)\n";
	some_distance_function();
	std::cout << std::endl;
}