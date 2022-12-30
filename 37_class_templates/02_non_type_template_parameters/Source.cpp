#include "boxcontainer.h"

template <typename T, T threshold>
class Point
{
	friend std::ostream& operator<<(std::ostream& out, const Point& operand);
public:
	Point(T x, T y) : m_x(x), m_y(y) {}
private:
	T m_x{};
	T m_y{};
};

template <typename T, T threshold>
std::ostream& operator<<(std::ostream& out, const Point<T, threshold>& operand)
{
	out << "Point [ x : " << operand.m_x << ",y : " << operand.m_y << "]";
	return out;
}

int main()
{
	BoxContainer<int, 5> int_box; // One instance
	int_box.add(11);
	int_box.add(62);
	int_box.add(30);
	int_box.add(3);
	int_box.add(7);
	int_box.add(9); // Won't be added
	int_box.add(8); // Won't be added
	std::cout << "int_box: " << int_box << std::endl;

	BoxContainer<int, 6> int_box1; // Another instance (check at: https://cppinsights.io/)

	std::cout << "\n=======================================\n\n";

	Point<int, 44> point(10, 10);  // Works
	Point<double, 0.0> point1(10.0, 10.0); // Works only with C++20, otherwise
												// Compiler Error, double not a valid non-type parameter
												// only integral types that can represent sizes or ranges allowed

	return 0;
}