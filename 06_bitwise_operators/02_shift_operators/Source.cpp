/*
 * The bitwise shift operator expressions have two forms:
 *		1) lhs << rhs - left shift of lhs by rhs bits
 *		2) lhs >> rhs -	right shift of lhs by rhs bits
 */

#include <iostream>
#include <bitset>
#include <typeinfo> // With this header we can check the variable type.

int main()
{
	unsigned short int value{ 0xff0u };

	std::cout << "size of short int: " << sizeof(short int) << std::endl; // 2 bytes, 16 bits

	std::cout << "value (bin): " << std::bitset<16>(value)
		<< ", value (dec): " << value << std::endl;

	// Bit shifting is not supported for types that are smaller than 4 bytes.
	// Variable val will be int, compiler will implicit cast from short int to in.
	auto val = (value >> 1); // shift right by 1 bit

	// Checking type of the variable
	std::cout << "Type of variable val is: " << typeid(val).name() << std::endl; // int

	return 0;
}