#include "shape.h"

//int Shape::m_count{ 0 }; // Old style, after C++17 we can mark static variable as inline and initialize in same place

Shape::Shape() : Shape("NoDescription"){}
Shape::Shape(std::string_view description) : m_description(description)
{
	m_count++;
}
Shape::~Shape()
{
	m_count--;
}
