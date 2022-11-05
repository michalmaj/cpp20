#include "square.h"
#include <iostream>

Square::Square(double side_param)
	: Square{ side_param, "black", 6 } // We can only delegate constructors in initializer list
									   // also we can't initialize anything else
{
	//Square{ side_param, "black", 6 }; // In here we only create a local temporary object
	std::cout << "One param constructor called\n";
	m_position = 45.8; // If we using a delegation, we can only initialize other things here
}

Square::~Square()
{
	std::cout << "Square object destroyed\n";
}

Square::Square(double side_param, const std::string& color_param, int shading_param)\
	: m_side(side_param), m_color(color_param), m_shading(shading_param)
{
	std::cout << "Three param constructor called\n";
}

double Square::surface() const
{
	return m_side * m_side;
}