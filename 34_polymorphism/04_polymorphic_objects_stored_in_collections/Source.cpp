#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main()
{

	Circle circle1(7.2, "circle1");
	Oval oval1(13.3, 1.2, "Oval1");
	Circle circle2(11.2, "circle2");
	Oval oval2(31.3, 15.2, "Oval2");
	Circle circle3(12.2, "circle3");
	Oval oval3(53.3, 9.2, "Oval3");

	std::cout << "sizeof(circle1): " << sizeof(circle1) << std::endl; // 64 - contains all of the information


	// If we store raw object data in an array set up to store base class objects
	// the data is going to be sliced off!

	// Standard array, objects will be sliced
	Shape shapes1[]{ circle1, oval1, circle2, oval2, circle3, oval3 };


	for (Shape& s : shapes1)
	{
		std::cout << "sizeof(object): " << sizeof(s) << std::endl; // 48 - sliced off
		s.draw(); // Shape::draw()
	}

	std::cout << "\n================================================\n\n";

	// What if we store in references?
	//const Shape& shapes2[]{ circle1, oval1, circle2, oval2, circle3, oval3 }; // Compiler Error: array of reference is not allowed
	//																		 // References are not left assignable

	// But we can use a reference wrapper and then we can draw our shapes
	// std::vector version
	std::vector<std::reference_wrapper<Shape>> shapes3{ circle1, oval1, circle2, oval2, circle3, oval3 };
	for(const auto& e : shapes3)
	{
		e.get().draw();
	}

	std::cout << std::endl;

	// C-Style array version
	std::reference_wrapper<Shape> shapes4[]{ circle1, oval1, circle2, oval2, circle3, oval3 };
	for (const auto& e : shapes4)
		e.get().draw();


	std::cout << "\n================================================\n\n";

	// Raw pointers
	Shape* shapes5[]{ &circle1, &oval1, &circle2, &oval2, &circle3, &oval3 };
	for(Shape* shape_ptr : shapes5)
	{
		std::cout << "Inside array, sizeof(*shape_ptr): " << sizeof(*shape_ptr) << std::endl;
		shape_ptr->draw();
		std::cout << std::endl;
	}

	std::cout << "\n================================================\n\n";

	// Smart pointers
	std::shared_ptr<Shape> shape_smart_ptr = std::make_shared<Circle>(circle1);
	shape_smart_ptr->draw();

	// Smart pointer and std::vector
	std::vector<std::shared_ptr<Shape>> t{ std::make_shared<Oval>(Oval{2.3, 9.8, "Oval"}), std::make_shared<Circle>(Circle{5.4, "Circle"}) };
	for (auto& e : t)
		e->draw();

	std::cout << std::endl;

	// Smart pointer and C-Style array
	std::shared_ptr<Shape> shapes6[]{ std::make_shared<Circle>(12.2, "Circle"), std::make_shared<Oval>(10.0, 20.0, "Oval") };

	for(const auto& s :shapes6)
	{
		s->draw();
	}

	return 0;
}