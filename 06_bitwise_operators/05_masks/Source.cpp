#include <iostream>
#include <iomanip>
#include <bitset>

int main()
{

	const int COLUMN_WIDTH{ 20 };

	// Highlight position for bit of interest with a 1
	// Mask other position with 0
	const unsigned char mask_bit_0{ 0b00000001 }; // Bit0
	const unsigned char mask_bit_1{ 0b00000010 }; // Bit0
	const unsigned char mask_bit_2{ 0b00000100 }; // Bit0
	const unsigned char mask_bit_3{ 0b00001000 }; // Bit0
	const unsigned char mask_bit_4{ 0b00010000 }; // Bit0
	const unsigned char mask_bit_5{ 0b00100000 }; // Bit0
	const unsigned char mask_bit_6{ 0b01000000 }; // Bit0
	const unsigned char mask_bit_7{ 0b10000000 }; // Bit0

	// Sandbox variable
	unsigned char var{ 0b00000000 }; // Starts off all bits off

	std::cout << std::setw(COLUMN_WIDTH) << "var: " << std::setw(COLUMN_WIDTH)
		<< std::bitset<8>(var) << std::endl;

	// Set a few bits: make them 1's regardles of what's in there

	// SETTING BITS
	// Setting: |= with mask of the bit

	// Set bit 1
	std::cout << "Setting bit in position 1" << std::endl;
	var |= mask_bit_1;
	std::cout << std::setw(COLUMN_WIDTH) << "var: " << std::setw(COLUMN_WIDTH)
		<< std::bitset<8>(var) << std::endl;

	// Set bit 5
	std::cout << "Setting bit in position 5" << std::endl;
	var |= mask_bit_5;
	std::cout << std::setw(COLUMN_WIDTH) << "var: " << std::setw(COLUMN_WIDTH)
		<< std::bitset<8>(var) << std::endl;

	// RESETTING BITS: set to 0
	// Resetting: &=(mask)

	// Reset bit 1
	std::cout << "Setting bit in position 1" << std::endl;
	// In mask we have 1, so we first evaluate parentheses (1 change to 0 and 0 to 1).
	// Our mask after complement operator (~ tilde): 11111110.
	var &=(compl mask_bit_1); // instead of sign '~' we can use compl keyword
	std::cout << std::setw(COLUMN_WIDTH) << "var: " << std::setw(COLUMN_WIDTH)
		<< std::bitset<8>(var) << std::endl;

	// Reset bit 5
	std::cout << "Setting bit in position 5" << std::endl;
	// In mask we have 1, so we first evaluate parentheses (1 change to 0 and 0 to 1).
	// Our mask after complement operator (~ tilde): 11011111.
	var &= (compl mask_bit_5); // instead of sign '~' we can use compl keyword
	std::cout << std::setw(COLUMN_WIDTH) << "var: " << std::setw(COLUMN_WIDTH)
		<< std::bitset<8>(var) << std::endl;

	// Set all bits
	std::cout << "Setting all bits" << std::endl;
	var |= (mask_bit_0 | mask_bit_1 | mask_bit_2 | mask_bit_3 |
		mask_bit_4 | mask_bit_5 | mask_bit_6 | mask_bit_7);
	std::cout << std::setw(COLUMN_WIDTH) << "var: " << std::setw(COLUMN_WIDTH)
		<< std::bitset<8>(var) << std::endl;

	// Reset bits as position 0, 2, 4, 6
	std::cout << "Reset bits as position 0, 2, 4, 6" << std::endl;
	var &= ~(mask_bit_0 | mask_bit_2 | mask_bit_4 | mask_bit_6);
	std::cout << std::setw(COLUMN_WIDTH) << "var: " << std::setw(COLUMN_WIDTH)
		<< std::bitset<8>(var) << std::endl;

	// Check state of a bit
	// We check a bit a given position and move them by same number of position to the
	// right. Mask has 1 only on the examined position the rest have 0. Our operation is
	// AND (&). So after moving by given bits to the right, our answer can be either 0 or 1
	std::cout << std::endl;
	std::cout << "Checking the state of each bit position (on/off)" << std::endl;
	std::cout << "bit0 is: " << ((var & mask_bit_0) >> 0) << std::endl;
	std::cout << "bit1 is: " << ((var & mask_bit_1) >> 1) << std::endl;
	std::cout << "bit2 is: " << ((var & mask_bit_2) >> 2) << std::endl;
	std::cout << "bit3 is: " << ((var & mask_bit_3) >> 3) << std::endl;
	std::cout << "bit4 is: " << ((var & mask_bit_4) >> 4) << std::endl;
	std::cout << "bit5 is: " << ((var & mask_bit_5) >> 5) << std::endl;

	// Instead of moving bits, we can also cast our result to boolean type
	std::cout << std::boolalpha;
	std::cout << "bit6 is: " << ((var & mask_bit_6) >> 6) << std::endl;
	std::cout << "bit6 is: " << static_cast<bool>(var & mask_bit_6) << std::endl;
	std::cout << "bit7 is: " << ((var & mask_bit_7) >> 7) << std::endl;
	std::cout << "bit7 is: " << static_cast<bool>(var & mask_bit_7) << std::endl;

	// Toggle bits
	// Toggle: var ^ mask

	// Toggle bit 0
	std::cout << std::endl;
	std::cout << "Toggle bit 0" << std::endl;
	var ^= mask_bit_0;
	std::cout << std::setw(COLUMN_WIDTH) << "var: " << std::setw(COLUMN_WIDTH)
		<< std::bitset<8>(var) << std::endl;

	// Toggle bit 7
	std::cout << std::endl;
	std::cout << "Toggle bit 7" << std::endl;
	var ^= mask_bit_7;
	std::cout << std::setw(COLUMN_WIDTH) << "var: " << std::setw(COLUMN_WIDTH)
		<< std::bitset<8>(var) << std::endl;


	return 0;
}