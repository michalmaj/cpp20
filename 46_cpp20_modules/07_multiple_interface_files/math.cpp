module;

module math;

// Preamble: imports
import print;

// Implementation
double add(double a, double b)
{
	return  a + b;
}

double dist(double x, double y)
{
	return sqrt(pow(x, 2) + pow(y, 2) * 1.0);
}

Point::Point(double x, double y)
	: m_x(x), m_y(y)
{
	std::cout << "Constructing Point object and greet John" << std::endl;
	greet("John");
}