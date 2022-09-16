/*
 * For generating a random number we can use a function std::rand()
 * Generate random number
 * Returns a pseudo-random integral number in the range between 0 and RAND_MAX.
 * This number is generated by an algorithm that returns a sequence of apparently
 * non-related numbers each time it is called. This algorithm uses a seed to generate the
 * series, which should be initialized to some distinctive value using function srand.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));

	// Create some random numbers
	int random_num = std::rand();
	std::cout << "random_num: " << random_num << std::endl; // 0 ~ RAND_MAX

	random_num = std::rand();
	std::cout << "random_num: " << random_num << std::endl; // 0 ~ RAND_MAX

	std::cout << "\n=====================================\n\n";

	// We can create random numbers in a loop
	for(size_t i{0}; i < 20; ++i)
	{
		random_num = std::rand();
		std::cout << "random_num " << i << ": " << random_num << std::endl; // 0 ~ RAND_MAX
	}

	std::cout << "\n=====================================\n\n";

	// Create a random number in certain range
	for (size_t i{ 0 }; i < 20; ++i)
	{
		random_num = std::rand() % 11;
		std::cout << "random_num " << i << ": " << random_num << std::endl; // [0 ~ 10]
	}

	std::cout << "\n=====================================\n\n";

	// If we want to start from different number than 0, we need to perform modulo operation
	// and then add this number
	for (size_t i{ 0 }; i < 20; ++i)
	{
		random_num = std::rand() % 10 + 1;
		std::cout << "random_num " << i << ": " << random_num << std::endl; // [1 ~ 10]
	}

	std::cout << "\n=====================================\n\n";

	// Show RAND_MAX
	std::cout << "RAND_MAX: " << RAND_MAX << std::endl;

	return 0;
}