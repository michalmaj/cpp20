#include <iostream>

size_t dog_count{ 0 }; // Global scope

unsigned int add_student()
{
	static unsigned int student_count{}; // The scope of this var is in this function, but lifetime
								// goes beyond the function execution
	student_count++;

	++dog_count; // Works - it's global variable

	return student_count;
}

void do_something()
{
	//student_count--; // Compiler Error, because this variable is only available inside
	//				 // add_student() function
	++dog_count; // Works - it's global variable
}

int main()
{

	//std::cout << "student count: " << add_student() << std::endl; // 1
	//std::cout << "student count: " << add_student() << std::endl; // 2
	//std::cout << "student count: " << add_student() << std::endl; // 3

	for(size_t i{0}; i <20; ++i)
		std::cout << "student count: " << add_student() << std::endl;
	std::cout << std::endl;

	return 0;
}