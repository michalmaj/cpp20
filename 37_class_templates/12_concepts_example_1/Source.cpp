#include <iostream>
#include <vector>
#include <concepts>

// It requires that we can print whatever T we have
template <typename T>
concept OutputStreamable = requires(std::ostream & o, T d)
{
	o << d;
};

template <OutputStreamable T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> vec)
{
	out << "[ ";
	for (const auto& e : vec)
		out << e << " ";
	out << "]";

	return out;
}

struct Point
{
	friend std::ostream& operator<<(std::ostream& o, const Point p)
	{
		o << "Point [x: " << p.m_x << ", y: " << p.m_y << "]";
		return o;
	}

	double m_x;
	double m_y;
};

int main()
{
	std::vector<int> numbers{ 1, 2, 3, 4, 5 };
	std::cout << "numbers: " << numbers << std::endl;

	std::vector<Point> points{ {10, 20}, {59, 45} };
	std::cout << "points: " << points << std::endl;


	return 0;
}