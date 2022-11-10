#include <iostream>
#include "outer.h"


int main()
{
	Outer::Inner inner1{ 5.6 };
	inner1.get_double();

	Outer outer1(10, 20.1);
	outer1.do_something();

	return 0;
}