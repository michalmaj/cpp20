#include <iostream>

// threshold is our non-type template parameter
template <int threshold, typename T>
bool is_valid(T collection[], size_t size)
{
	T sum{};
	for(size_t i{0}; i < size; ++i)
	{
		sum += collection[i];
	}
	return sum > threshold;
}

// Version making a little more sense for the task
template <typename T>
bool is_valid(T* collection, int threshold, size_t size)
{
	T sum{};
	for (size_t i{ 0 }; i < size; ++i)
	{
		sum += collection[i];
	}
	return sum > threshold;
}

// Support for C++20 NTTP is still not fully supported
template <typename T, double coeff>
T process(T a, T b)
{
	return a * b - coeff;
}

int main()
{
	double temperatures[]{ 10.0,20.0,30.0,40.0,50.0,100.0 };

	auto result = is_valid<200, double>(temperatures, std::size(temperatures));
	std::cout << std::boolalpha << "result: " << result << std::endl;

	std::cout << "\n======================================\n\n";

	auto result1 = is_valid<double>(temperatures, 200, std::size(temperatures));
	std::cout << std::boolalpha << "result1: " << result1 << std::endl;

	std::cout << "\n======================================\n\n";

	std::cout << "Support for non int type: " << process<double, 20.9>(10.2, 14.9) << std::endl;

	return 0;
}