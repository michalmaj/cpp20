#include <iostream>
#include "utility.h"

//void some_function();

void print_age_utility1();
void print_age_utility2();

int main()
{
	//some_function(); // Inaccessible from other translation unit, because function is marked as inline

	print_age_utility1();
	print_age_utility2();

	return 0;
}