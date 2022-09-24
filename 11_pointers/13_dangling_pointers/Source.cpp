#include <iostream>

int main()
{
	// Case1: Uninitialized pointer
	int* p_number; // Dangling uninitialized pointer

	std::cout << "Case1: Uninitialized pointer" << std::endl;

	// Compiler Error in both cases: uninitialized local variable used 
	//std::cout << "p_number: " << p_number << std::endl;
	//std::cout << "*p_number: " << *p_number << std::endl;

	std::cout << "\n===================================\n\n";


	// Case2: deleted pointer
	std::cout << "Case2: deleted pointer" << std::endl;
	int* p_number1{ new int{67} };

	std::cout << "*p_number1 (before delete): " << *p_number1 << std::endl;

	delete p_number1;

	//std::cout << "*p_number1 (after delete): " << *p_number1 << std::endl; // CRASH

	std::cout << "\n===================================\n\n";


	// Case3: multiple pointers pointing to same address
	std::cout << "Case3: multiple pointers pointing to same address" << std::endl;

	int* p_number3{ new int{83} };
	int* p_number4{ p_number3 };

	std::cout << "p_number3: " << p_number3 << " " << *p_number3 << std::endl;
	std::cout << "p_number4: " << p_number4 << " " << *p_number4 << std::endl;

	delete p_number3;

	// p_number4 points to deleted memory. Dereferencing it will lead to
	// undefined behavior: Crash/garbage or whatever
	//std::cout << "p_number4 (after deleting p_number3): " << p_number4 << " " << *p_number4
	//	<< std::endl;

	std::cout << "\n===================================\n\n";


	// Solution1: Initialize pointers immediately upon declaration
	std::cout << "Solution1: Initialize pointers immediately upon declaration:" << std::endl;
	int* p_number5{};
	int* p_number6{ new int{56} };

	// Check for nullptr before use
	if (p_number6 != nullptr)
		std::cout << "*p_number6: " << *p_number6 << std::endl;
	else
		std::cout << "Invalid address!" << std::endl;

	std::cout << "\n===================================\n\n";


	// Solution2: right after you call delete on a pointer, remember to reset
	// the pointer to nullptr to make it CLEAR it doesn't point enywhere
	std::cout << "Solution2: set pointer to nullptr after deletion:" << std::endl;

	int* p_number7{ new int{82} };

	//Use the pointer however you want
	std::cout << "p_number7 - " << p_number7 << " - " << *p_number7 << std::endl;

	delete p_number7;
	p_number7 = nullptr; // Reset the pointer

	//Check for nullptr before use
	if (p_number7 != nullptr) {
		std::cout << "*p_number7 : " << *p_number7 << std::endl;
	}
	else {
		std::cout << "Invalid memory access!" << std::endl;
	}

	std::cout << "\n===================================\n\n";


	// Solution 3: for multiple pointers pointing to the same address. Make sure there is
	// one clear pointer (master pointer) that owns the memory ( responsible for releasing when
	// necessary) , other pointers should only be able to dereference when the master pointer is valid

	std::cout << std::endl;
	std::cout << "Solution 3: use one pointer as a master and rest as a slaves:" << std::endl;
	int* p_number8{ new int{382} };// Let's say p_number8 is the master pointer
	int* p_number9{ p_number8 };

	//Dereference the pointers and use them
	std::cout << "p_number8 - " << p_number8 << " - " << *p_number8 << std::endl;

	if (!(p_number8 == nullptr)) { // Only use slave pointers when master pointer is valid
		std::cout << "p_number9 - " << p_number9 << " - " << *p_number9 << std::endl;
	}

	delete p_number8; // Master releases the memory
	p_number8 = nullptr;

	if (!(p_number8 == nullptr)) { // Only use slave pointers when master pointer is valid
		std::cout << "p_number9 - " << p_number9 << " - " << *p_number9 << std::endl;
	}
	else {
		std::cerr << "WARNING : Trying to use an invalid pointer" << std::endl;
	}

	return 0;
}