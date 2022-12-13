#include "shape.h"
#include "ellipse.h"
#include <memory>

int main()
{
	//Shape
	Shape shape1{ "shape1" };
	std::cout << "Shape count: " << Shape::m_count << std::endl; // 1

	Shape shape2{ "shape2" };
	std::cout << "Shape count: " << Shape::m_count << std::endl; // 2

	Shape shape3{ "shape3" };
	std::cout << "Shape count: " << Shape::m_count << std::endl; // 3

	std::cout << "*********************************************************" << std::endl;

	// Ellipse
	Ellipse ellipse1{ 10, 12, "ellipse1" };
	std::cout << "Shape count: " << Shape::m_count << std::endl; // 4 - because ellipse is also shape
	std::cout << "Ellipse count: " << Ellipse::m_count << std::endl; // 1

	// Shape polymorphism
	std::unique_ptr<Shape> shapes[]{ std::make_unique<Shape>(shape1), std::make_unique<Ellipse>(ellipse1) };

	for (const auto& shape : shapes)
		std::cout << "count: " << shape->get_count() << std::endl;


	return 0;
}