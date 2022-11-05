#include "cylinder.h"

#include <numbers>

// Constructors
Cylinder::Cylinder(double rad_param, double height_param)
	: base_radius{rad_param}, height{height_param} // Initializer list
{}

// Setters and getters
void Cylinder::set_base_radius(double rad_param)
{
	base_radius = rad_param;
}
void Cylinder::set_height(double height_param)
{
	height = height_param;
}

double Cylinder::get_base_radius() const
{
	return base_radius;
}
double Cylinder::get_height() const
{
	return height;
}

// Methods
double Cylinder::volume() const
{
	return std::numbers::pi * base_radius * base_radius * height;
}