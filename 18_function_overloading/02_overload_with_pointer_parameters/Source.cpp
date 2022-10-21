#include <iostream>
#include <limits>

double max(const double* numbers, const size_t count)
{
	double maximum{ std::numeric_limits<double>::min() };

	for(size_t i{0}; i < count; ++i)
	{
		if (numbers[i] > maximum)
			maximum = numbers[i];
	}
	return maximum;
}

//int max(const int numbers[], const size_t count) // All three is the same
//int max(const int numbers[6], const size_t count)
int max(const int* numbers, const size_t count)
{
	int maximum{ std::numeric_limits<int>::min() };

	for (size_t i{ 0 }; i < count; ++i)
	{
		if (numbers[i] > maximum)
			maximum = numbers[i];
	}
	return maximum;
}

// Both functions above can be replaced by:
template <class T, size_t N>
T max(const T(&number)[N])
{
	T maximum = std::numeric_limits<T>::min();

	for(const auto& e : number)
	{
		if (e > maximum)
			maximum = e;
	}
	return maximum;
}

int main()
{
	double  doubles[]{ 10.0,30.0,12.3 };
	int  ints[]{ 1,2,5,2,8,4 };

	auto result = max(ints, std::size(ints));
	std::cout << "result : " << result << std::endl;

	//  Call template function
	auto result1 = max(doubles);
	std::cout << "result1 : " << result1 << std::endl;

	return 0;
}