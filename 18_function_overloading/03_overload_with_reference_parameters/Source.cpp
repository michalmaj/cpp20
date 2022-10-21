#include <iostream>
#include <string>

// Ambiguous calls - comment out one of those
void say_my_name(const std::string& name)
{
	std::cout << "Your name is (ref): " << name << std::endl;
}

void say_my_name(const std::string name)
{
	std::cout << "Your name is (non ref): " << name << std::endl;
}


// Implicit conversion
double max(double a, double b) {
	std::cout << "double max called" << std::endl;
	return (a > b) ? a : b;
}


//int& max(int& a, int& b)
const int& max(const int& a, const int& b)
{
	std::cout << "int max called" << std::endl;
	return (a > b) ? a : b;
}

int main()
{
	std::string name{ "John" };
	//say_my_name(name); // Compiler Error: Ambiguous call.

	//say_my_name("Arya"); // Compiler Error: The compiler knows how to take a temporary const char*
	//					 // string and turn that into a reference. So both functions are still
	//					 // valid for this call, Ambiguous

	char a{ 6 };
	char b{ 9 };


	auto result = max(a, b); // without any changes double version will be call, because
								 // implicit conversion exclude int version of max function
								 // if we have a non const parameters

	return 0;
}