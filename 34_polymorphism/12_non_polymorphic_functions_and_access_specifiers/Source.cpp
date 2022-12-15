#include "shape.h"
#include "ellipse.h"
#include <memory>


int main()
{

	// Accessing stuff through the base class pointer
	std::shared_ptr<Shape> shape0 = std::make_shared<Ellipse>(1, 5, "ellipse0");
	shape0->draw(); // Static binding
	//shape0->func(); // Compiler Error: func is private in Shape class

	std::cout << "\n==========================================\n\n";

	// Direct objects: static binding
	Ellipse ellipse1{ 1, 6, "ellipse1" };
	ellipse1.func(); // Works: it is a public function from Ellipse class
	//ellipse1.draw(); // Compiler Error: draw() is private in Ellipse

	std::cout << "\n==========================================\n\n";

	// Raw derived object assigned to raw base object
	// Slicing will occur, Shape::draw() will be called
	Shape shape3 = Ellipse{ 2, 3, "ellipse3" };
	shape3.draw(); // Shape::draw() called
	//shape3.func(); // Shape::func() called, but it is private: Compiler Error


	return 0;
}