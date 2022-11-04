#include <iostream>

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
	Point p1;

	p1.x = 5;
	p1.y = 6;
	print_point(p1);

	auto& [a, b] = p1;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	
	p1.x = 44.1;
	p1.y = 55.2;
	print_point(p1);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	auto func = [&a, &b]()
	{
		std::cout << "a(captured): " << a << std::endl;
		std::cout << "b(captured): " << b << std::endl;
	};

	func();

	return 0;
}