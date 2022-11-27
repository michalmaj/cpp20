/*
 * Putting together all the conversion techniques between types:
 *	- custom type conversion operator: Number -> Point;
 *	- Constructors: constructing Point from Number: Number -> Point;
 *	- Copy assignment operator for other types: Copying from Number: Number -> Point.
 *
 * Start with all these in, and show that the compiler uses this priority for the assignment: p1 = n1
 *	- copy assignment;
 *	- constructor;
 *	type conversion operator.
 *
 * For the function:
 *	- constructor;
 *	- type conversion operator;
 *	- copy assignment operator is not a candidate!
 */

#include <iostream>
#include "point.h"
#include "number.h"

void do_something_with_point(const Point& p) {
	std::cout << "point : " << p << std::endl;
}

int main()
{

	Point p1{ 10, 10 };
	Number n1{ 22 };


	//// (1) Copy assignment operator
	//// (2) Constructor taking in a Number
	//// (3) Type conversion operator: Number -> Point
	//p1 = n1;


	// (1) Compiler Error (msc) - can't have both constructor for Number class and Type conversion operator from Number to Point
	// (2) Both above have the same priority
	do_something_with_point(n1);

	return 0;
}