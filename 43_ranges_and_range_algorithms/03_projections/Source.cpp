#include <iostream>
#include <algorithm>
#include <vector>
#include "point.h"

template <typename T>
void print_collection(const T& collection)
{
	std::cout << "collection [";
	for (const auto& e : collection)
		std::cout << " " << e;
	std::cout << " ]" << std::endl;
}

int main()
{
	// Projections: usually the sorting is done based on operator<
	// but we get one chance to write operator<. Sometimes we want
	// to sort thing based on another scheme or member variable
	// other that the one used by operator<. We can do that with
	// projections. For example, sorting based on y for Point can
	// be achieved with a y projections as shown in this example

	std::cout << std::endl;
	std::cout << "Sorting points (default: based on length):" << std::endl;
	std::vector<Point> points{ {10, 90}, {30, 70}, {20, 80} };

	print_collection(points);

	// Sorting with the default comparator
	std::ranges::sort(points, std::less<>()); // Default sort based on distance
	print_collection(points);

	std::cout << "\n================================================\n\n";

	// Sorting with a projections: the data is passed into the projection before
	// it's passed int the comparator. std::less<> is going to compare two doubles
	// instead of comparing length() from origin.
	std::cout << std::endl;
	std::cout << "Sorting points (projection on Point::m_x):" << std::endl;

	print_collection(points);

	//std::ranges::sort(points, std::less<>(), [](const auto& p) {return p.m_x; }); /// Will work with public data
	//std::ranges::sort(points, std::less<>(),&Point::m_x;); // Will work with public data
	std::ranges::sort(points, std::less<>(), [](const auto& p) {return p.get_x(); });

	print_collection(points);

	std::cout << "\n================================================\n\n";

	// Projection with for_each
	std::cout << std::endl;
	std::cout << "Projection with for_each:" << std::endl;

	auto print = [](const auto& n) {std::cout << " " << n; };
	using pair = std::pair<int, std::string>;
	std::vector<pair> pairs{ {1, "one"}, {2, "two"}, {3, "three"} };

	std::cout << "projection with pair::first: ";
	std::ranges::for_each(pairs, print, [](const pair& p) {return p.first; });
	std::cout << std::endl;

	std::cout << "projection with pair::first: ";
	std::ranges::for_each(pairs, print, &pair::first);
	std::cout << std::endl;

	std::cout << "projection with pair::second: ";
	std::ranges::for_each(pairs, print, [](const pair& p) {return p.second; });
	std::cout << std::endl;








	return 0;
}