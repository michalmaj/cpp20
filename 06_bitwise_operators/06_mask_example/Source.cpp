#include <iostream>


void use_options_v0(bool flag0, bool flag1, bool flag2, bool flag3,
	bool flag4, bool flag5, bool flag6, bool flag7)
{
	std::cout << "Flag0: " << flag0 << ", do something with it" << std::endl;
	std::cout << "Flag1: " << flag1 << ", do something with it" << std::endl;
	std::cout << "Flag2: " << flag2 << ", do something with it" << std::endl;
	std::cout << "Flag3: " << flag3 << ", do something with it" << std::endl;
	std::cout << "Flag4: " << flag4 << ", do something with it" << std::endl;
	std::cout << "Flag5: " << flag5 << ", do something with it" << std::endl;
	std::cout << "Flag6: " << flag6 << ", do something with it" << std::endl;
	std::cout << "Flag7: " << flag7 << ", do something with it" << std::endl;
}

struct Masks
{
	const unsigned char mask_bit_0{ 0b00000001 }; // Bit0
	const unsigned char mask_bit_1{ 0b00000010 }; // Bit1
	const unsigned char mask_bit_2{ 0b00000100 }; // Bit2
	const unsigned char mask_bit_3{ 0b00001000 }; // Bit3
	const unsigned char mask_bit_4{ 0b00010000 }; // Bit4
	const unsigned char mask_bit_5{ 0b00100000 }; // Bit5
	const unsigned char mask_bit_6{ 0b01000000 }; // Bit6
	const unsigned char mask_bit_7{ 0b10000000 }; // Bit7
};

void use_options_v1(unsigned char flags)
{
	const Masks mask;
	
	std::cout << "bit0 is: " << ((flags & mask.mask_bit_0) >> 0) << std::endl;
	std::cout << "bit1 is: " << ((flags & mask.mask_bit_1) >> 1) << std::endl;
	std::cout << "bit2 is: " << ((flags & mask.mask_bit_2) >> 2) << std::endl;
	std::cout << "bit3 is: " << ((flags & mask.mask_bit_3) >> 3) << std::endl;
	std::cout << "bit4 is: " << ((flags & mask.mask_bit_4) >> 4) << std::endl;
	std::cout << "bit5 is: " << ((flags & mask.mask_bit_5) >> 5) << std::endl;
	std::cout << "bit6 is: " << ((flags & mask.mask_bit_6) >> 6) << std::endl;
	std::cout << "bit7 is: " << ((flags & mask.mask_bit_7) >> 7) << std::endl;
}

int main()
{
	use_options_v0(0, 0, 1, 1, 1, 0, 1, 0);

	const Masks mask;
	use_options_v1(mask.mask_bit_2 | mask.mask_bit_3 | mask.mask_bit_4 | mask.mask_bit_6);




	return 0;
}