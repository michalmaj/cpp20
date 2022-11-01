#include <iostream>
#include <numbers>

class Cylinder
{
public:
	// Constructors
	Cylinder() = default;

	// If we crate own constructor, the compiler won't generate default constructor for us.
	// So we have to create it be ourselves i.e., like above.
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

	// Setters and getters
	double get_base_radius() const
	{
		return base_radius;
	}

	double get_height() const
	{
		return height;
	}

	void set_base_radius(double rad_param)
	{
		base_radius = rad_param;
	}

	void set_height(double height_param)
	{
		height = height_param;
	}

private:
	// Member variables
	double base_radius{1};
	double height{1};
};

int main()
{
	Cylinder cylinder1{ 10, 10 };
	std::cout << "volume: " << cylinder1.volume() << std::endl;

	// Modify our object
	cylinder1.set_base_radius(100);
	cylinder1.set_height(10);
	std::cout << "volume: " << cylinder1.volume() << std::endl;


	return 0;
}