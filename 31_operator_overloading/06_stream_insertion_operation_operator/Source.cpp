#include "point.h"

int main()
{
	Point p1{ 10, 20 };

	//// If operator<< will be overload as a member function, our syntax will be awkward
	//p1 << std::cout;
	//std::cout << std::endl;
	//// Behind the scene we are doing:
	//p1.operator<<(std::cout);
	//std::cout << std::endl;

	// Better version, where operator<< is a standalone function:
	std::cout << p1 << std::endl;

	// It also allows us to chain print any number of objects
	Point p2{ 3, 4 };

	std::cout << p1 << " " << p2 << std::endl;


	return 0;
}