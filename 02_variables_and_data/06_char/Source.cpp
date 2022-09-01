/*
 * Single letter we can store as char.
 * Char occupies 1 byte in the memory.
 * It can store 256 different values from 0 to 255
 */

#include <iostream>

int main()
{
	char char1{ 'a' };
	char char2{ 'r' };
	char char3{ 'r' };
	char char4{ 'o' };
	char char5{ 'w' };

	std::cout << char1 << std::endl;
	std::cout << char2 << std::endl;
	std::cout << char3 << std::endl;
	std::cout << char4 << std::endl;
	std::cout << char5 << std::endl;

	// value from 0 to 255 hiding behind char value
	char value = 65; // it's a letter 'A' in ASCII code
	std::cout << "value: " << value << std::endl;
	std::cout << "(int)value: " << static_cast<int>(value) << std::endl;

	return 0;
}