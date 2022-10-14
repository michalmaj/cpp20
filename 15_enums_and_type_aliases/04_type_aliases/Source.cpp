#include <iostream>

int main()
{
	// If we don't want to type many times in our programs unsigned long long int
	// we can use a type aliases:
	using HugeInt = unsigned long long int; // Recommended in modern C++

	//// Older version:
	//typedef unsigned long long int HugeInt;

	//unsigned long long int huge_number{ 123456789 }; // normal version

	HugeInt huge_number{ 123456789 }; // version with type aliases

	std::cout << "huge_number: " << huge_number << std::endl;

	return 0;
}