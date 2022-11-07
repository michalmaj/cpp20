#include <iostream>

class Point
{
public:
	Point(double x, double y) : m_x{x}, m_y{y}
	{
		std::cout << "Point constructor called\n";
	}

private:
	double m_x;
	double m_y;
};

struct Person
{
	std::string m_name;
	unsigned int m_age;
};

int main()
{
	Point p1{ 10.9, 39.3 }; // Uniform initialization () or {}

	Person person1{ "Michael", 36 }; // {} - protecting for narrowing conversion

	Person person2("John", 41.9); // () - not protecting from narrowing conversion

	int students[]{ 1, 2, 3, 4, 5, 6, 7 }; // {} - protecting for narrowing conversion

	int students1[](1, 2, 3, 4, 5, 6, 7.3); // - not protecting from narrowing conversion


	return 0;
}