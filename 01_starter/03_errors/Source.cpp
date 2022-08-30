/*
 * There are three kinds of errors:
 *	1) Compile Time Errors
 *	2) Runtime Errors
 *	3) Warnings
 *
 * Goal of developer is generate a binary executable file from C++ code. 
 */


// Standard library header
// This header is part of the input/output library.
#include <iostream>

int main()
{

	// Example of compile time error - no semicolon at end of statement
	//std::cout << "Hello C++20!" << std::endl // comment out to skip this error

	// Example of runtime error - out of bound for array
	int arr[2]{ 1, 2 }; // example of an array
	//std::cout << arr[-100000] << std::endl; // comment out to skip this error

	// Example of warning error - it won't be a 0.5
	// The 1 is an integer and the 2 is an integer, so the
	// result also will be an integer - in this case - 0
	//1 / 2; // comment out to skip this error

	return 0;
}