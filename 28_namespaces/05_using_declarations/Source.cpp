#include "point.h"
#include "line.h"
#include "cylinder.h"
#include "operations.h"

//using Geom::Cylinder; // Bring name from namespace
//using Geom::Point;

using namespace Geom; // Bring whole namespace

//using Math::add;
//using namespace Math;

double add(double a, double b)
{
	std::cout << "::add" << std::endl;
	return a + b + 0.555;
}

int main()
{
	Point p1{ 10, 20 };
	Point p2{ 3.4, 6.1 };
	p1.print_info();
	p2.print_info();

	std::cout << "\n==============================\n\n";

	Geom::Line l1{ p1, p2 };
	l1.print_info();

	std::cout << "\n==============================\n\n";

	Cylinder c1{ 1.4, 10 };
	std::cout << "Volume: " << c1.volume() << std::endl;

	std::cout << "\n==============================\n\n";

	add(10, 20);

	Math::add(10, 20);

	Math_Weighted::add(10, 20);

	std::cout << "\n==============================\n\n";

	//using std::cout;
	//using std::endl;
	using namespace std; // NOT RECOMMENDED

	cout << "Hello World" << endl;

	return 0;
}