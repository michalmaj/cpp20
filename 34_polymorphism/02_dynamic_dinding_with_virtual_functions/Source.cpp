#include "shape.h"
#include "oval.h"
#include "circle.h"
#include <memory>

void draw_shape(const Shape* s)
{
	s->draw();
}

void draw_shape(const Shape& s)
{
	s.draw();
}

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
	shape_ptr->draw(); // draw oval

	shape_ptr = &circle1;
	shape_ptr->draw(); // draw circle

	std::cout << "\n======================================\n\n";

	// smart pointers
	std::unique_ptr<Shape> shape_smart = std::make_unique<Shape>(Shape{ "ShapeSmart" });
	shape_smart->draw();
	shape_smart = std::make_unique<Circle>(Circle{ 3.0, "CircledSmart" });
	shape_smart->draw();
	shape_smart = std::make_unique<Oval>(Oval{ 2.2, 3.4, "OvalSmart" });
	shape_smart->draw();

	std::cout << "\n======================================\n\n";

	// base references
	Shape& shape_ref{ shape1 };
	shape_ref.draw(); // draw shape

	Shape& oval_ref{ oval1 };
	oval_ref.draw(); // draw oval

	Shape& circle_ref{ circle1 };
	circle_ref.draw(); // draw circle



	std::cout << "\n======================================\n\n";

	// Drawing shapes
	draw_shape(&oval1); // Draw by pointer
	draw_shape(circle1); // Draw by reference

	std::cout << "\n======================================\n\n";

	// Raw pointers
	shape_ptr = &oval1;
	//shape_ptr->get_x_rad(); // Compiler Error, polymorphism works only with virtual methods

	// Shapes stored in collection
	Shape* shape_collection[]{ &shape1, &oval1, &circle1 };

	for(const Shape* e : shape_collection)
	{
		e->draw();
	}



	return 0;
}