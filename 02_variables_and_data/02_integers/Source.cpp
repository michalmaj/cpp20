/*
 * Data types int (Integer) stores decimals, typically occupies 4 bytes
 * or more in memory.
 * Using data types we can create variables.
 * Variable is a named piece of memory that store specific types of data.
 *
 * We have four ways to initialize our variables:
 *	1) Braced initialization using {}
 *	2) Functional initialization using ()
 *	3) Assignment Initialization using =
 *	4) Leave without initialization - variable will store garbage data.
 *
 * Typically declaration and initialization of variable looks like this:
 * typename variable_name {value};
 */

#include <iostream>
#include <typeinfo> // let us to check variable data type

int main()
{
	// variable declaration without initialization
	// variable may contain random garbage value
	int elephant_count;
	//std::cout << "Garbage data: " << elephant_count << std::endl; // some compilers generate error

	// Initialization using {}
	int lion_count{}; // initialize to 0
	std::cout << "Lions: " << lion_count << std::endl;

	int dog_count{ 3 }; // intialize to 1
	std::cout << "Dogs: " << dog_count << std::endl;

	int cat_count{ 5 };
	std::cout << "Cats: " << cat_count << std::endl;

	// we can use an expression as initializer
	// expression can be for example addition
	int domestic_animals{ dog_count + cat_count };
	std::cout << "Number of domestic animals: " << domestic_animals << std::endl;

	// Remember initialization using curly braces is safe initialization
	// For example, if you try initialize integer variable by float point
	// number compiler won't let you do this
	//int narrowing_conversion{ 3.7 }; // compiler error, requires narrowing conversion

	// we can't use undeclared variables
	//int my_number{new_data}; // compiler error, new_data is undefined

	// Initialization using ()
	// It's very similar to {} initialization
	int apple_count(5);
	std::cout << "Apples: " << apple_count << std::endl;

	int orange_count(10);
	std::cout << "Oranges: " << orange_count << std::endl;

	int fruit_count(apple_count + orange_count);
	std::cout << "Fruits: " << fruit_count << std::endl;

	// This time we can use narrowing conversion (we get only a warning)
	int narrowing_conversion_functional(4.7);
	// but we lost the data after .
	std::cout << "After narrowing conversion: " << narrowing_conversion_functional << std::endl;

	// Initialization using =
	int bike_count = 2;
	std::cout << "Bikes: " << bike_count << std::endl;

	int truck_count = 7;
	std::cout << "Trucks: " << truck_count << std::endl;

	int vehicle_count = bike_count + truck_count;
	std::cout << "Vehicles: " << vehicle_count << std::endl;

	// this conversion will work same as functional conversion
	int narrowing_converion_assignment = 6.9;
	std::cout << "After narrowing conversion: " << narrowing_converion_assignment << std::endl;


	// We can also check size and type of variable
	std::cout << "sizeof int: " << sizeof(int) << std::endl;
	std::cout << "sizeof truck_count: " << sizeof(truck_count) << std::endl;
	std::cout << "type of truck_count: " << typeid(truck_count).name() << std::endl;


	return 0;
}