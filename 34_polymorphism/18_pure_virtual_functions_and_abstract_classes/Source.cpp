#include <iostream>
#include <memory>
#include <typeinfo>

#include "circle.h"
#include "rectangle.h"


int main()
{
	//// Check to see if we can create an object of abstract class
	//std::unique_ptr<Shape> shape_ptr = std::make_unique<Shape>(); // Compiler Error: cannot instantiate abstract class

	// But we can use a base pointer to manage a rectangle object
	const std::unique_ptr<Shape> shape_rect = std::make_unique<Rectangle>(10, 10, "rect1");
	double surface = shape_rect->surface();
	std::cout << "Dynamic type of shape_rect: " << typeid(*shape_rect).name() << std::endl;
	std::cout << "The surface os shape_rect is: " << surface << std::endl;
	
	std::cout << "\n==========================================\n\n";

	// Base pointer to manage a circle object
	const std::unique_ptr<Shape> shape_circle = std::make_unique<Circle>(10, "circle1");
	surface = shape_circle->surface();
	std::cout << "Dynamic type of shape_circle: " << typeid(*shape_circle).name() << std::endl;
	std::cout << "The surface os shape_circle is: " << surface << std::endl;

	return 0;
}