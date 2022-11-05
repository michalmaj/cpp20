#pragma once
class Cylinder
{
public:
	// Constructors
	Cylinder() = default; 
	Cylinder(double rad_param, double height_param = 5); 

	// Setters and getters
	void set_base_radius(double rad_param);
	void set_height(double height_param);

	double get_base_radius() const;
	double  get_height() const;

	// Methods
	double volume() const;

private:
	// Member variables
	double base_radius{ 1 };
	double height{ 1 };
};

