#include <iostream>

double add(double a, double b)
{
	return a + b;
}

int main()
{
	int x{ 5 }; // x, y, and z are all lvalues, they have a memory address we
	int y{ 10 }; // can retrieve and use later on
	int z{ 20 }; // as long as the variables are in scope

	int* ptr = &x; // x is lvalue so its address can be stored in pointer

	z = (x + y);
	std::cout << "z: " << z << std::endl;
	//std::cout << "&(x + y): " << &(x + y) << std::endl; // (x + y) is a temporary value (rvalue), & needs lvalue

	std::cout << "\n======================================\n\n";

	double result = add(10.1, 20.2); // The result of add(10.1, 20.2) is stored in some memory location for a short time,
										 // before it's assignment to result, and after it's copied into result, the memory is
										 // reclaimed by the system. add(10.1, 20.2) is an lvalue.

	//std::cout << "address of add(10.1, 20.2): " << &(add(10.1, 20.2)) << std::endl; // Compiler Error: & requires lvalue
	std::cout << "result: " << result << std::endl;

	std::cout << "\n======================================\n\n";

	// Try to grab some addresses for later use
	//int* ptr1 = &(x + y); // Compiler Error: & requires lvalue
	//double* ptr2 = &(add(10.1, 20.2)); // Compiler Error: & requires lvalue
	//int* ptr3 = &45; // Compiler Error: & requires lvalue
	int* ptr4 = &x; // OK, x is an lvalue, so we can grab its address


	return 0;
}