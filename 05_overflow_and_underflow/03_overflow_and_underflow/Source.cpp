#include <iostream>

int main()
{
	// Overflow
	unsigned char data{ 250 }; // 0~255 range

	// If we increment over 255 we get an overflow.
	++data;
	std::cout << "data: " << static_cast<int>(data) << std::endl; // 251

	++data;
	std::cout << "data: " << static_cast<int>(data) << std::endl; // 252

	++data;
	std::cout << "data: " << static_cast<int>(data) << std::endl; // 253

	++data;
	std::cout << "data: " << static_cast<int>(data) << std::endl; // 254

	++data;
	std::cout << "data: " << static_cast<int>(data) << std::endl; // 255

	++data;
	std::cout << "data: " << static_cast<int>(data) << std::endl; // 0, overflow

	// If we decrement below 0 we get an underflow
	data = 1;
	--data;
	std::cout << "data: " << static_cast<int>(data) << std::endl; // 0

	--data;
	std::cout << "data: " << static_cast<int>(data) << std::endl; // 255, underflow


	return 0;
}