#include <iostream>
#include <cstring>

// Function template
template <typename T> T maximum(T a, T b)
{
	return (a > b) ? a : b;
}

// A raw overload will take precedence over any template instance
// if const char* is passed to maximum function
const char* maximum(const char* a, const char* b)
{
	std::cout << "Raw overload called" << std::endl;
	return (std::strcmp(a, b)) ? a : b;
}

// Overload through templates. Will take precedence over raw T
// if a pointer is passed to maximum
template <typename T> T* maximum(T* a, T* b)
{
	std::cout << "Template overload called (T*) " << std::endl;
	return (*a > *b) ? a : b;
}

int main()
{
	const char* g{ "wild" };
	const char* h{ "animal" };

	const char* result = maximum(g, h);

	std::cout << "max(const char*): " << result << std::endl;

	std::cout << "\n====================================================\n\n";

	int a{ 810 };
	int b{ 23 };

	auto result1 = maximum(&a, &b);
	std::cout << "result1: " << *result1 << std::endl;

  	return 0;
}