#include "shape.h"
#include "oval.h"
#include "circle.h"
#include <functional>


int main()
{
	Circle circle1(7.2, "circle1");
	Oval oval1(13.3, 1.2, "Oval1");
	Circle circle2(11.2, "circle2");
	Oval oval2(31.3, 15.2, "Oval2");
	Circle circle3(12.2, "circle3");
	Oval oval3(53.3, 9.2, "Oval3");

	std::reference_wrapper<Shape> shapes[]{ circle1, oval1, circle2, oval2, circle3, oval3 };

	for(const auto& shape : shapes)
	{
		shape.get().draw();
		std::cout << std::endl;
	}

	return 0;
}