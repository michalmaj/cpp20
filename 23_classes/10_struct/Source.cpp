#include <iostream>


// Private by default
class Dog
{
	std::string m_name;
};

// Public by default
struct Cat
{
	std::string m_name;
};

struct Point
{
	double x;
	double y;
};

void print_point(const Point& p)
{
	std::cout << "Point [x: " << p.x << ", y: " << p.y << "]" << std::endl;
}

int main()
{
	Dog dog1;
	Cat cat1;

	//dog1.m_name = "Fluffy"; // Compiler error if m_name is private
	cat1.m_name = "Kitty"; // Everything OK
	std::cout << cat1.m_name << std::endl;


	Point p1;
	p1.x = 10;
	p1.y = 55.5;
	print_point(p1);

	p1.x = 40.4;
	p1.y = 2.7;
	print_point(p1);

	return 0;
}