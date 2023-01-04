#include "boxcontainer.h"
#include <type_traits>


template <typename T>
	requires std::is_arithmetic_v<T>
class Point
{
public:
	Point() = default;
	Point(T x, T y) : m_x(x), m_y(y) {}

	friend std::ostream& operator<<(std::ostream& out, const Point<T> operand)
	{
		out << "Point [x: " << operand.m_x << ", y: " << operand.m_y << "]";
		return out;
	}

private:
	T m_x;
	T m_y;
};

struct Dog
{
	
};

struct Cat
{
	~Cat() = delete;
};

int main()
{
	// Numbers - check to see if something is proper type
	//static_assert(std::floating_point<int>); // Fails
	//static_assert(std::floating_point<double>); // Works

	// Equality and order
	// https://en.cppreference.com/w/cpp/concepts/equality_comparable
	//static_assert(std::equality_comparable<int>); // Works
	//static_assert(std::equality_comparable_with<double, std::string>); //Fails

	//static_assert(std::totally_ordered<int>); // Works
	//static_assert(std::totally_ordered<Point<int>>); // Fails - needs all comparison operators


	// std::same_as
	//static_assert(std::same_as<int, int>); // Success
	//static_assert(std::same_as<int, double>); // Fail
	//static_assert(std::same_as<BoxContainer<int>, BoxContainer<int>>); // Success
	//static_assert(std::same_as<BoxContainer<int>, BoxContainer<double>>); // Fail
	//static_assert(std::same_as<Point<int>, Point<int>>); // Success
	//static_assert(std::same_as<Point<int>, Point<float>>); // Fail
	//static_assert(std::same_as<Dog, Cat>); // Fail

	// std::destructible
	//static_assert(std::destructible<Dog>); // Success
	//static_assert(std::destructible<Cat>); // Fail


	return 0;
}