module;

#include <cstring> // C function includes must show up here

module math;

// Implementation
double add(double a, double b)
{
	return  a + b;
}

void greet(const std::string& name)
{
	std::string dest = "Hello ";
	dest.append(name);
	std::cout << dest << std::endl;
}

void print_name_length(const char* c_str_name)
{
	std::cout << "Length: " << std::strlen(c_str_name) << std::endl;
}

double dist(double x, double y)
{
	return sqrt(pow(x, 2) + pow(y, 2) * 1.0);
}

Point::Point(double x, double y)
	: m_x(x), m_y(y)
{

}
