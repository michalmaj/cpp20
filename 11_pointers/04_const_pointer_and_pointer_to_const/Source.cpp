/*
 * If const is on the left of * the data is const (can't modify the data).
 * If const is on the right of * the pointer is const (can't point somewhere else).
 */

#include <iostream>


int main()
{
	// A raw variable that can be modified
	std::cout << std::endl;
	std::cout << "A raw variable that can be modified:" << std::endl;

	int number{ 5 }; // Non constant, can change number any way we want
	std::cout << "number: " << number << std::endl;
	std::cout << "&number: " << &number << std::endl;

	// Modify
	number = 12;
	number += 7;

	std::cout << "number: " << number << std::endl;
	std::cout << "&number: " << &number << std::endl;


	std::cout << "\n=========================================\n" << std::endl;

	// Pointer: can modify the data and the pointer itself
	int* p_number1{ nullptr };
	int number1{ 23 };

	p_number1 = &number1;
	std::cout << "Pointer and value pointed to: both modifiable:" << std::endl;
	std::cout << "p_number1: " << p_number1 << std::endl; // Address
	std::cout << "*p_number1: " << *p_number1 << std::endl; // 23
	std::cout << "number1: " << number1 << std::endl; // 23

	// Change the pointed to value through pointer
	std::cout << std::endl;
	std::cout << "Modifying the value pointed to p_number1 through the pointer:" << std::endl;
	*p_number1 = 432;
	std::cout << "p_number1: " << p_number1 << std::endl; // Address
	std::cout << "*p_number1: " << *p_number1 << std::endl; // 432
	std::cout << "number1: " << number1 << std::endl; // 432

	// Change the pointer itself to make it point somewhere else
	std::cout << std::endl;
	std::cout << "Changing the pointer itself to make it point somewhere else:" << std::endl;
	int number2{ 56 };
	p_number1 = &number2;
	std::cout << "p_number1: " << p_number1 << std::endl; // Address
	std::cout << "*p_number1: " << *p_number1 << std::endl; // 56
	std::cout << "number1: " << number1 << std::endl; // 432
	std::cout << "number2: " << number2 << std::endl; // 56

	std::cout << "\n=========================================\n" << std::endl;

	// Pointer to const
	// Pointer pointing to const data: You can't modify the data through pointer
	std::cout << "Pointer is modifiable, pointed to value is constant:" << std::endl;
	int number3{ 632 }; // Although you can omit the const on number3 here it is still
					    // going to complie, it advise to be explicit as possible in
						// in your code and put the const in front. Make sure intents CLEAR

	const int* p_number3{ &number3 }; // Can't modify number3 through p_number3

	std::cout << "p_number3: " << p_number3 << std::endl; // Address
	std::cout << "*p_number3: " << *p_number3 << std::endl; // 632


	// Modifying the value pointed to by p_number3 through pointer (Compiler Error)
	std::cout << std::endl;
	std::cout << "Modifying the value pointed to by p_number3 through pointer (Compiler Error)" << std::endl;
	//*p_number3 = 444; // Compiler Error

	// Although we can't change what's pointed to by p_number3
	// we can still change where it's pointing
	std::cout << std::endl;
	std::cout << "Changing the address pointed to by p_number3" << std::endl;
	int number4{ 872 };
	p_number3 = &number4;

	std::cout << "p_number3: " << p_number3 << std::endl; // Address
	std::cout << "*p_number3: " << *p_number3 << std::endl; // 872

	std::cout << "\n=========================================\n" << std::endl;

	// const keyword applies to the variable name
	std::cout << "const keyword applies to the variable name:" << std::endl;

	int protected_var{ 10 }; // Can make it const to protect it if we want. Show this

	// p_protected_var is a pointer to const data, we can't
	// modify the data through this pointer: regardless of
	// whether the data itself is declared const or not
	const int* p_protected_var{ &protected_var };

	//*p_protected_var = 55;
	protected_var = 65;
	std::cout << "protected_var: " << protected_var << std::endl; // 65
	std::cout << "p_protected_var: " << p_protected_var << std::endl; // Address
	std::cout << "*p_protected_var: " << *p_protected_var << std::endl; // 65
	std::cout << std::endl;

	// You can't set up a modifiable pointer to const data through,
	// you'll get a compiler error: Invalid conversion from 'const type*' to 'type*'.
	const int some_data{ 55 };
	//int* p_some_data{ &some_data }; // Compiler Error

	std::cout << "\n=========================================\n" << std::endl;

	// Both pointer and pointed to value are constant
	const int number5{ 459 };
	const int* const p_number5{ &number5 };
	std::cout << "Pointer is constant, value pointed to is constant:" <<  std::endl; 
	std::cout << "p_number5: " << p_number5 << std::endl; // Address
	std::cout << "*p_number5: " << *p_number5 << std::endl; // 459
	std::cout << std::endl;

	// Can't modify the pointed to value through the pointer
	std::cout << "Changing value pointed to by p_number5 through the pointer (Compile Error)"
		<< std::endl;
	//*p_number5 = 222; // CE: Trying to assign to read only location

	// Can't change where the pointer is pointing to: The pointer is now itself constant.
	std::cout << "Changing the pointer p_number5 address itself(Compile Error)" << std::endl;
	int number6{ 333 };
	//p_number5 = &number6; // CE: Trying to assign to read only location
	std::cout << std::endl;

	std::cout << "\n=========================================\n" << std::endl;

	// Pointer is constant (can't make it point anywhere else)
	// but pointed to value can change
	std::cout << "Pointer is constant, pointed to value can change:" << std::endl;
	int number7{ 982 };

	int* const p_number7{ &number7 };
	std::cout << "p_number7: " << p_number7 << std::endl; // Address
	std::cout << "*p_number7: " << *p_number7 << std::endl; // 982

	std::cout << "Changing value pointed to through p_number7 pointer:" << std::endl;
	*p_number7 = 456;
	std::cout << "p_number7: " << p_number7 << std::endl; // Address
	std::cout << "*p_number7: " << *p_number7 << std::endl; // 456

	int number8{ 2928 };
	std::cout << "Changing the address where p_number7 is pointing (Compile Error)." << std::endl;
	//p_number7 = &number8; // Compiler Error

	return 0;
}