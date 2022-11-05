/*
 * Member wise copy vs Initializer lists
 *
 * Member wise copy:
 *	- Two steps:
 *		1. object creation;
 *		2. member variable assignment.
 *	- Potential unnecessary copies of data.
 *	- Order of member variables doesn't matter.
 *
 * Initializer list:
 *	- Initialization happens at real object creation.
 *	- Unnecessary copies avoided.
 *	- Order of member variables matters.
 */

#include <iostream>
#include "cylinder.h"

int main()
{
	Cylinder c1{ 5 };
	std::cout << "base_rad : " << c1.get_base_radius() << std::endl;
	std::cout << "height : " << c1.get_height() << std::endl;
	std::cout << "volume : " << c1.volume() << std::endl;
	return 0;
}