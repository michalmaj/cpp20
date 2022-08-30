/*
 * We have four basics stream
 *	1) std::cout  - printing data to the console (terminal)
 *	2) std::cin - reading data from the terminal
 *	3) std::cerr - printing error to the console
 *	4) std::clog - printing log messages to the console
 */

#include <iostream>
#include <string> // THis library is needed to use std::getline


int main()
{
	// print some messages
	std::cout << "Hello world" << std::endl;

	std::cout << "My number is: " << 42 << std::endl;

	int age{ 18 };
	std::cout << "The age is: " << age << std::endl;


	// print error
	std::cerr << "std::cerr output: Something went wrong!" << std::endl;

	// print log message
	std::clog << "std::clog output: Some log message!" << std::endl;

	// read data
	// variable string to store names
	std::string name;

	std::cout << "Enter your name: ";
	std::cin >> name; // you can only enter your name or surname, using space
					  // makes our program runs into problems

	std::cout << "Enter your age: ";
	std::cin >> age;

	std::cout << "Hello " << name << "! You are " << age << " years old!" << std::endl;

	// To avoid problem with spaces during entering full name
	// we have to use std::getline()
	// In addition we need to clear cin, you have to use these two commands:
	std::cin.ignore(); // discard the trailing
	std::cin.clear(); // clear the error flags
	std::string full_name;
	std::cout << "Enter your full name: ";
	std::getline(std::cin, full_name);
	std::cout << "Your full name is: " << full_name << std::endl;
	

	return 0;
}