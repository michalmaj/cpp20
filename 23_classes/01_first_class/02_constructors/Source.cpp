#include <iostream>
#include <numbers>

class Cylinder
{
public:
	// Constructors
	Cylinder()
	{
		base_radius = 2.0;
		height = 2.0;
	}

	Cylinder(double rad_param, double height_param)
	{
		base_radius = rad_param;
		height = height_param;
	}

	// Methods
	double volume() const
	{
		return std::numbers::pi * base_radius * base_radius * height;
	}

private:
	// Properties
	double base_radius{};
	double height{};
};

int main()
{
	Cylinder cylinder1; // object
	std::cout << "volume: " << cylinder1.volume() << std::endl;

	Cylinder cylinder2{10.4, 5.6};
	std::cout << "volume: " << cylinder2.volume() << std::endl;



	return 0;
}