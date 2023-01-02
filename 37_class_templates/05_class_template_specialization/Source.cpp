#include "adder.h"



int main()
{
	Adder<int> adder_int;
	adder_int.do_something();
	std::cout << adder_int.add(10, 20) << std::endl;

	std::cout << "\n==============================================\n\n";

	// Char*
	char str1[20]{ "Hello" };
	char str2[]{ "World" };
	Adder<char*> adder_c_str;
	adder_c_str.do_something(); // If we don't put this method into our template specialization we will get a Compiler Error 
	std::cout << adder_c_str.add(str1, str2) << std::endl; // Without template specialization it will be a Compiler Error

	return 0;
}
