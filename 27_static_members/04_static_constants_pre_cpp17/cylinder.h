#pragma once

#include <string>

class Cylinder
{
public:
	// int and enum can be initialized in header
	static const int INT_CONSTANT = 5;
	enum Color{Red=0, Green, Blue};
	static const Color COLOR_CONSTANT = Color::Blue;

	// Other have to be done in the cpp file
	static const std::string default_color;
	static const char* CHAR_PTR_CONSTANT;
	static const int INT_ARRAY_CONSTANT[5];
	static const float FLOAT_CONSTANT;
	static const std::string STRING_ARRAY_CONSTANT[2];

	// Not static, they can be only initialized in initializer list
	const float WEIRD_FLOAT;
	const char* WEIRD_C_STRING;
	const int WEIRD_INT_ARRAY_CONSTANT[5];


	// Constructors
	Cylinder() = default;
	Cylinder(double radius_param, double height_param);

	// Getters
	double get_base_radius() const;
	double get_height() const;

	// Setters
	void set_base_radius(double radius_param);
	void set_height(double height_param);

	// Methods
	double volume() const;

private:
	double base_radius{ 1.0 };
	double height{ 1.0 };
	static const double PI;
};

