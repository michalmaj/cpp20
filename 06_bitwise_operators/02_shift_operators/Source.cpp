/*
 * The bitwise shift operator expressions have two forms:
 *		1) lhs << rhs - left shift of lhs by rhs bits
 *		2) lhs >> rhs -	right shift of lhs by rhs bits
 *
 * As long as we don't lose our data due to shifting right or left, we can calculate
 * our new value:
 *		1) for left shift:
 *			old_value * 2^n,
 *			where n is number of shifting bits
 *		2) for right shift
 *			old_dat / 2^n,
 *			where n is number of shifting bits
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
	// Variable res will be int, compiler will implicit cast from short int to in.
	auto res = (value >> 1); // shift right by 1 bit

	// Checking type of the variable
	std::cout << "Type of variable res is: " << typeid(res).name() << std::endl; // int

	// But we can explicit cast to short int.
	value = static_cast<unsigned short int>(value << 1); // Shift left.
	std::cout << "value (bin): " << std::bitset<16>(value)
		<< ", value (dec): " << value << std::endl;

	// Shift left by one once more
	value = static_cast<unsigned short int>(value << 1); // Shift left.
	std::cout << "value (bin): " << std::bitset<16>(value)
		<< ", value (dec): " << value << std::endl;

	// Shift left by one once more
	value = static_cast<unsigned short int>(value << 1); // Shift left.
	std::cout << "value (bin): " << std::bitset<16>(value)
		<< ", value (dec): " << value << std::endl;

	// Shift left by one once more (after next shit left, we will lose our data)
	value = static_cast<unsigned short int>(value << 1); // Shift left.
	std::cout << "value (bin): " << std::bitset<16>(value)
		<< ", value (dec): " << value << std::endl;

	// Shift left by one once more (we lost 1 bit)
	value = static_cast<unsigned short int>(value << 1); // Shift left.
	std::cout << "value (bin): " << std::bitset<16>(value)
		<< ", value (dec): " << value << std::endl;

	// We can't it back even using reverse operation (shift right).
	// Once we are loosing our data  moving left or right, we are not able
	// to bring this data back.
	// Shift right once
	value = static_cast<unsigned short int>(value >> 1); // Shift right.
	std::cout << "value (bin): " << std::bitset<16>(value)
		<< ", value (dec): " << value << std::endl;


	// Shift multiple bits in one go
	value = static_cast<unsigned short int>(value >> 4); // Shift right for 4 bits.
	std::cout << "value (bin): " << std::bitset<16>(value)
		<< ", value (dec): " << value << std::endl;


	// Rememebr if you want to print directly in std::cout, use parentheses
	std::cout << "value: " << (value >> 1) << std::endl;


	return 0;
}