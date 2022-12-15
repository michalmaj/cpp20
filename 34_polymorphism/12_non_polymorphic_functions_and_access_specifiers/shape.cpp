#include "shape.h"

Shape::Shape() : Shape("NoDescription"){}
Shape::Shape(std::string_view description) : m_description(description){}