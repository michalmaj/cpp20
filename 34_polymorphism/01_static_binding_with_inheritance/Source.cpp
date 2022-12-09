#include "shape.h"
#include "oval.h"
#include "circle.h"

void draw_circle(const Circle& circle)
{
	circle.draw();
}

void draw_oval(const Oval& oval)
{
	oval.draw();
}

// More functions as we deal with more shapes. 30? 70? 100?. It's bad designing.

int main()
{
	Shape shape1{ "Shape1" };
	shape1.draw(); // Draw shape

	Oval oval1{ 2.0, 3.5, "Oval1" };
	oval1.draw(); // draw oval

	Circle circle1{ 3.3, "Circle1" };
	circle1.draw(); // draw oval

	std::cout << "\n======================================\n\n";

	// Base pointers
	Shape* shape_ptr = &shape1;
	shape_ptr->draw(); // draw shape

	shape_ptr = &oval1;
	shape_ptr->draw(); // draw shape!

	shape_ptr = &circle1;
	shape_ptr->draw(); // draw shape as well!!

	std::cout << "\n======================================\n\n";

	// base references
	Shape& shape_ref{ shape1 };
	shape_ref.draw(); // draw shape

	Shape& oval_ref{ oval1 };
	oval_ref.draw(); // draw shape!

	Shape& circle_ref{ circle1 };
	circle_ref.draw(); // draw shape as well!

	std::cout << "\n======================================\n\n";

	// Drawing
	draw_circle(circle1);
	draw_oval(oval1);

	// Shapes stored in collections
	// Right now we need separate collections for any shape types
	Circle circle_collection[]{ circle1, Circle(10.0, "Circle2"), Circle(20.0, "Circle3") };
	Oval oval_collection[]{ oval1, Oval(22.3, 51.1, "Oval2") };
	// More arrays as we have more shape types, 100? Bad designing!

	return 0;
}