#include <iostream> // it's how we add a library to our program

consteval int get_value()
{
	return 47;
}

// the main function is a special function
// it's a starting point of C++ program
// so any valid program can only has ONE main function
int main()
{
	constexpr int value{ get_value() };

	// std::cout is a part of iostream, let's us to print to the console
	std::cout << "value: " << value << std::endl; // std::endl print a new line

	// return 0 to system means that the program executed successfully
	return 0;
}