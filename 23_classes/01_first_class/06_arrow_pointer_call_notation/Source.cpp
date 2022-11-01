#include <iostream>
#include "cylinder.h"



int main()
{
	Cylinder cylinder1{ 10, 10 };
	std::cout << "volume: " << cylinder1.volume() << std::endl;

	// Managing a stack object through pointers
	Cylinder* p_cylinder1 = &cylinder1;

	// In this case first we need to dereference the pointer and then call the volume method
	std::cout << "volume: " << (*p_cylinder1).volume() << std::endl;

	// But there is better version, we can use a -> operator
	std::cout << "volume: " << p_cylinder1->volume() << std::endl;

	// Create a cylinder heap object through the new operator
	Cylinder* p_cylinder2 = new Cylinder(100, 2);

	std::cout << "volume(p_cylinder2): " << p_cylinder2->volume() << std::endl;
	std::cout << "bese_radius(p_cylinder2): " << p_cylinder2->get_base_radius() << std::endl;

	delete p_cylinder2;
	p_cylinder2 = nullptr;
	return 0;
}