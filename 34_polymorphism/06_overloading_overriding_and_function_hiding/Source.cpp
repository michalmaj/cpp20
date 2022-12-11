#include "shape.h"
#include "oval.h"
#include "circle.h"
#include <memory>

int main()
{
	Circle circle1{ 7.2, "Circle1" };
	Oval oval1{ 13.3, 1.2, "Oval1" };

	circle1.draw();
	circle1.draw(44);

	oval1.draw();
	oval1.draw(54);

	std::cout << "\n====================================\n\n";

	std::unique_ptr<Shape> shape_ptr = std::make_unique<Circle>(10, "Circle1");

	shape_ptr->draw(45, "Red"); // draw method with 2 parameters is not known at the Shape level

	return 0;
}