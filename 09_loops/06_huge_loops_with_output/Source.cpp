#include <iostream>
#include <chrono> // header for count execution time

int main()
{
	const int COUNT{ 10'000 };

	auto start1 = std::chrono::high_resolution_clock::now();
	for(size_t i{0}; i < COUNT; ++i)
	{
		std::cout << "i: " << i << std::endl;
	}
	std::cout << "Done!" << std::endl;
	auto stop1 = std::chrono::high_resolution_clock::now();
	auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);

	auto start2 = std::chrono::high_resolution_clock::now();
	for (size_t i{ 0 }; i < COUNT; ++i)
	{
		std::cout << "i: " << i << "\n";
	}
	std::cout << "Done!" << std::endl;
	auto stop2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);

	auto start3 = std::chrono::high_resolution_clock::now();
	for (size_t i{ 0 }; i < COUNT; ++i)
	{
		//std::cout << "i: " << i << "\n";
	}
	std::cout << "Done!" << std::endl;
	auto stop3 = std::chrono::high_resolution_clock::now();
	auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);

	std::cout << "Execution time with std::cout and std::endl: " << duration1 << std::endl;
	std::cout << "Execution time with std::cout and \\n: " << duration2 << std::endl;
	std::cout << "Execution time without printing: " << duration3 << std::endl;

	return 0;
}