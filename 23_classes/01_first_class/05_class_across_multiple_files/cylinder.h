#pragma once

#include "constants.h"

class Cylinder
{
public:
	// Constructors
	Cylinder() = default;

	// If we crate own constructor, the compiler won't generate default constructor for us.
	// So we have to create it be ourselves i.e., like above.
	Cylinder(double rad_param, double height_param);

	// Methods
	double volume() const;

	// Setters and getters
	double get_base_radius() const;

	double get_height() const;

	void set_base_radius(double rad_param);

	void set_height(double height_param);

private:
	// Member variables
	double base_radius{ 1 };
	double height{ 1 };
};

