#include <iostream>

int main()
{
	int decimal_number = 15; // decimal
	int octal_number = 017; // octal
	int hexadecimal_number = 0x0F; // hexadecimal
	int binary_number = 0b00001111; // binary

	std::cout << "decimal_number: " << decimal_number << std::endl;
	std::cout << "octal_number: " << octal_number << std::endl;
	std::cout << "hexadecimal_number: " << hexadecimal_number << std::endl;
	std::cout << "binary_number: " << binary_number << std::endl;

	return 0;
}