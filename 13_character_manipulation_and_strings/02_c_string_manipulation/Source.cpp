/*
 * https://en.cppreference.com/w/cpp/header/cstring
 */

#include <iostream>

int main()
{

	// std::strlen: find the length of a string
	// real arrays and those decayed into pointer
	std::cout << "std::strlen" << std::endl;
	const char message1[]{ "The sky is blue." };
	std::cout << "message1: " << message1 << std::endl;

	// Array decays into pointer when we use const char*
	const char* message2{ "The sky is blue." };
	std::cout << "message2: " << message2 << std::endl;

	// std::strlen ignores null character
	std::cout << "std::strlen(message1): " << std::strlen(message1) << std::endl;

	// sizeof includes null character
	std::cout << "sizeof(message1): " << sizeof(message1) << std::endl;

	// std::strlen works with decayed arrays
	std::cout << "std::strlen(message2): " << std::strlen(message2) << std::endl;

	// sizeof prints only size of pointer
	std::cout << "sizeof(message2): " << sizeof(message2) << std::endl;

	std::cout << "\n==================================================\n\n";

	// std:strcmp - signature: int strcmp(const char* lhs, const char* rhs);
	// Returns negative value if lhs appears before rhs in lexicographical order,
	// zero if lhs and rhs compare equal and positive if lsh appear after rhs in
	// lexicographical order
	std::cout << "std::strcmp" << std::endl;

	const char* string_data1{ "Alabama" };
	const char* string_data2{ "Blabama" };

	char string_data3[]{ "Alabama" };
	char string_data4[]{ "Blabama" };

	// Print out the comparison
	std::cout << "std::strcmp (" << string_data1 << ", " << string_data2 << "): "
		<< std::strcmp(string_data1, string_data2) << std::endl;

	std::cout << "std::strcmp (" << string_data3 << ", " << string_data4 << "): "
		<< std::strcmp(string_data3, string_data4) << std::endl;

	// We can change the pointers to point somewhere else (if they are not const pointers)
	string_data1 = "Alabama";
	string_data2 = "Alabamb";

	//// But we can't change where our array points
	//string_data3 = "Alabama"; // CE
	//string_data4 = "Alabamb"; // CE

	// Print out the comparison
	std::cout << "std::strcmp (" << string_data1 << ", " << string_data2 << "): "
		<< std::strcmp(string_data1, string_data2) << std::endl;

	string_data1 = "Alacama";
	string_data2 = "Alabama";

	//Print out the comparison
	std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << "): "
		<< std::strcmp(string_data1, string_data2) << std::endl;

	string_data1 = "India";
	string_data2 = "France";

	//Print out the comparison
	std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << "): "
		<< std::strcmp(string_data1, string_data2) << std::endl;

	string_data1 = "Kigali";
	string_data2 = "Kigali";

	//Print out the comparison
	std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << "): "
		<< std::strcmp(string_data1, string_data2) << std::endl;

	std::cout << "\n==================================================\n\n";

	// std:strncmp - signature: int strcmp(const char* lhs, const char* rhs, size_t count);
	// Compares n characters in the string.
	// Returns negative value if lhs appears before rhs in lexicographical order,
	// zero if lhs and rhs compare equal and positive if lsh appear after rhs in
	// lexicographical order
	std::cout << "std::strncmp" << std::endl;

	string_data1 = "Alabama";
	string_data2 = "Blabama";
	size_t n{ 3 };

	std::cout << "std::strncmp (" << string_data1 << ", " << string_data2 << "): "
		<< std::strncmp(string_data1, string_data2, n) << std::endl;

	string_data1 = "aaaia";
	string_data2 = "aaance";

	std::cout << "std::strncmp (" << string_data1 << ", " << string_data2 << "): "
		<< std::strncmp(string_data1, string_data2, n) << std::endl;

	n = 5;

	std::cout << "std::strncmp (" << string_data1 << ", " << string_data2 << "): "
		<< std::strncmp(string_data1, string_data2, n) << std::endl;

	std::cout << "\n==================================================\n\n";

	// FInd the first occurrence of a character
	std::cout << "std::strchr" << std::endl;
	// https://en.cppreference.com/w/cpp/string/byte/strchr

	// We can also use std::strchr to find all the characters one by one
	const char* const str{ "Try not. Do, or do not. There is no try." };
	char target = 'T';
	const char* result = str;
	unsigned int iterations{ 0 };

	while((result = std::strchr(result, target)) != nullptr)
	{
		std::cout << "Found '" << target << "' starting at '" << result << "'\n";

		// Increment result, otherwise we will find target at the same location
		result++;
		iterations++;
	}

	std::cout << "iterations : " << iterations << std::endl;

	std::cout << "\n==================================================\n\n";

	// BAd version of above code
	std::cout << "std::strchr" << std::endl;
	const char* str2{ "Try not. Do, or do not. There is no try." };
	char target2 = 'T';
	const char* result2{ nullptr };
	size_t iterations2{};
	while ((result2 = std::strchr(str2, target2)) != nullptr) {
		std::cout << "Found '" << target2
			<< "' starting at '" << result2 << "'\n";
		// Increment result, otherwise we'll find target at the same location
		++str2; // Making the pointer point to the next character
		++iterations2;
	}
	std::cout << "iterations : " << iterations2 << std::endl;

	std::cout << "\n==================================================\n\n";

	// Find last occurrence
	std::cout << "std::strrchr" << std::endl;

	char input[]{ "/home/user/hello.cpp" };
	char* output = std::strrchr(input, '/');
	if (output)
		std::cout << output + 1 << std::endl; // +1 because we want to start printing past
											  // the character found by std::strrchr.





	return 0;
}