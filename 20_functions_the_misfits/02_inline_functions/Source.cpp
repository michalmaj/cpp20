#include <iostream>

inline int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	int a{ 5 };
	int b{ 8 };

	std::cout << "max: " << max(a, b) << std::endl;

	return 0;
}