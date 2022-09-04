/*
 * constexpr - specifies that the value of a variable or function can appear
 * in constant expressions.
 *
 * The constexpr specifier declares that it is possible to evaluate the value
 * of the function or variable at compile time.
 */

#include <iostream>

int main()
{
	constexpr int SOME_LIB_MAJOR_VERSION{ 123 };

	constexpr int eye_count{ 2 };
	constexpr  double PI{ 3.14 };

	//eye_count = 4; // constexp implies const, can't modify data

	std::cout << "eye count: " << eye_count << std::endl;
	std::cout << "PI: " << PI << std::endl;

	int leg_count{ 2 }; // runtime variable

	//constexpr int arm_count{ leg_count }; // runtime variable, can't be use to
	//									  // initialize constexpr variable

	// but either constexpr and cont variable can be use to initialize constexpr
	constexpr int room_count{ 10 };
	constexpr int door_count{ room_count }; // Works

	const int table_count{ 5 };
	constexpr int chair_count{ table_count * 5 }; // It's OK as well

	// using constexpr variables we can for example check something at compile time
	// if it fails our program won't compile
	static_assert(SOME_LIB_MAJOR_VERSION == 123);

	// static assert won't work with runtime variables
	int age{ 5 };
	//static_assert(age == 5); // expression must have a constant value

	return 0;
}