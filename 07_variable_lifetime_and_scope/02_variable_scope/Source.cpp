/*
 * Scope:
 * A region in our code where a variable name can be mentioned. You may be reading from it,
 * writing into it, basically using it in any conceivable way.
 * Trying to use a variable out of it's scope will result in a compiler error. 
 */

#include <iostream>

//// You can't use variables before declaration!
//global_var1 = 60; // Compiler Error: usage before declare.

// After declaration of this variable we can use it anywhere in a file
int global_var1{ 23 }; // Global variable

void some_function()
{
	// Local variable, accessible only in this block (inside this function in this case).
	int local_var{ 10 };
	std::cout << "Inside function global_var: " << global_var1 << std::endl;
	std::cout << "Inside function local_var: " << local_var << std::endl;
}

void some_other_function()
{
	//// Can't use local variable from another function in this function.
	//local_var = 20;
}

int main()
{

	std::cout << "Inside main function global_var: " << global_var1 << std::endl;

	//// Can't use local variable from another function in this function (even in main).
	//local_var = 20;
	return 0;
}