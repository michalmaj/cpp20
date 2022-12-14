#include <iostream>
#include <memory>
#include "Shape.h"
#include "Ellipse.h"

int main()
{
	// Accessing stuff through the base class pointer
	std::shared_ptr<Shape> shape0{ std::make_shared<Ellipse>(1, 5, "ellipse0") };
	shape0->draw();
	//shape0->func(); // Compiler Error, func() is private in Shape class

	std::cout << "\n========================================\n\n";

	// Direct objects: static binding
	Ellipse ellipse1(1, 6, "Ellipse");
	//ellipse1.draw(); // Compiler Error: draw() is private is Ellipse class - static binding
	ellipse1.func(); // Works

	std::cout << "\n========================================\n\n";

	// Raw derived object assigned to raw base object
	// Slicing will occur, Shape::draw will be called
	Shape shape3{ Ellipse{2, 3, "ellipse3"} };
	shape3.draw(); // Shape::draw() called
	//shape3.func(); // Compiler Error: func() is private in shape

	return 0;
}