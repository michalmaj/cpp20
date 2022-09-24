#include <iostream>

int main()
{
	//int* data = new int[10000000000000000]; // Error

	//for (size_t i{ 0 }; i < 1000000; ++i)
	//	int* data = new int[10000000000]; // Error as well

	//// Exception mechanism
	//try
	//{
	//	int* data = new int[10000000000000000];
	//}catch (std::exception& ex)
	//{
	//	std::cout << "Caught exception: " << ex.what() << std::endl;
	//}

	// std::nothrow
	int* data = new(std::nothrow) int[10000000000000000];

	if (data != nullptr)
		std::cout << "Data allocated" << std::endl;
	else
		std::cout << "Data allocated failed" << std::endl;

	return 0;
}