/*
 * Bitwise logic operators
 * The bitwise arithmetic operator expressions have the form:
 * 1) ~ rhs it is a bitwise NOT, takes one number and inverts all bits of it.
 * 2) lhs & rhs it is a bitwise AND, takes two numbers as operands and does AND on every bit
 *	  of two numbers. The result of AND is 1 only if both bits are 1.
 * 3) lhs | rhs it is a bitwise OR, takes two numbers as operands and does OR on every bit
 *    of two numbers. The result of OR is 1 if any of the two bits is 1. 
 * 4) lhs ^ rhs it is a bitwise XOR,  takes two numbers as operands and does XOR on every bit
 *    of two numbers. The result of XOR is 1 if the two bits are different.
 */
#include <iostream>
#include <bitset>
#include <iomanip>


int main()
{

	const int COLUMN_WIDTH{ 20 };
	unsigned char value1{ 0x3 }; // 0000 0011
	unsigned char value2{ 0x5 }; // 0000 0101

	std::cout << std::setw(COLUMN_WIDTH) << "value1: "
		<< std::setw(COLUMN_WIDTH) << std::bitset<8>(value1) << std::endl;
	std::cout << std::setw(COLUMN_WIDTH) << "value2: "
		<< std::setw(COLUMN_WIDTH) << std::bitset<8>(value2) << std::endl;

	// Bitwise AND (&)
	std::cout << std::endl;
	std::cout << "Bitwise AND (&):" << std::endl;
	std::cout << std::setw(COLUMN_WIDTH) << "value1 & value2: "
		<< std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 & value2) << std::endl;
	std::cout << std::endl;

	// Bitwise OR (|)
	std::cout << std::endl;
	std::cout << "Bitwise OR (|):" << std::endl;
	std::cout << std::setw(COLUMN_WIDTH) << "value1 | value2: "
		<< std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 | value2) << std::endl;
	std::cout << std::endl;

	// Bitwise XOR (^)
	std::cout << std::endl;
	std::cout << "Bitwise XOR (^):" << std::endl;
	std::cout << std::setw(COLUMN_WIDTH) << "value1 ^ value2: "
		<< std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 ^ value2) << std::endl;
	std::cout << std::endl;

	// Bitwise NOT (~)
	std::cout << std::endl;
	std::cout << "Bitwise NOT (~):" << std::endl;
	std::cout << std::setw(COLUMN_WIDTH) << "~value1: "
		<< std::setw(COLUMN_WIDTH) << std::bitset<8>(~value1) << std::endl;
	std::cout << std::setw(COLUMN_WIDTH) << "~value2: "
		<< std::setw(COLUMN_WIDTH) << std::bitset<8>(~value2) << std::endl;
	std::cout << std::setw(COLUMN_WIDTH) << "~01011001: "
		<< std::setw(COLUMN_WIDTH) << std::bitset<8>(~0b01011001) << std::endl; // bin literal
	std::cout << std::setw(COLUMN_WIDTH) << "~01011001: "
		<< std::setw(COLUMN_WIDTH) << std::bitset<8>(~0x59) << std::endl; // hex literal
	std::cout << std::endl;

	return 0;
}