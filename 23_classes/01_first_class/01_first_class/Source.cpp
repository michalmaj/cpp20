/*
 *	- Class member variables can either be raw stack variables or
 *	  pointers.
 *	- Members can't be references.
 *	- Classes have function (methods) that let them do things.
 *	- Class methods have access to the member variables, regardless
 *	  or whether they are public or private.
 *	- Private members of classes aren't accessible from the outside
 *	  of the class definition.
 *
 */

#include <iostream>
#include <numbers>

class Cylinder
{
public:
	// function (method)
	double volume()
	{
		return std::numbers::pi * base_radius * base_radius * height;
	}

	// Member variables
	double base_radius{};
	double height{};
};

int main()
{
	Cylinder cylinder1; // object
	std::cout << "volume: " << cylinder1.volume() << std::endl;
	std::cout << "base_radius: " << cylinder1.base_radius << std::endl;
	std::cout << "height: " << cylinder1.height << std::endl;

	// Change the data
	cylinder1.base_radius = 10;
	cylinder1.height = 3;
	std::cout << "volume: " << cylinder1.volume() << std::endl;


	cylinder1.height = 8;
	std::cout << "volume: " << cylinder1.volume() << std::endl;

	
	return 0;
}