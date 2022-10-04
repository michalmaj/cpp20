#include <iostream>
#include <string>

int main()
{
	std::string str1{ "Hello there" };

	// Size of a string: doesn't count the null terminator
	std::cout << "str1.size(): " << str1.size() << std::endl;

	std::cout << "\n===============================================\n\n";

	// Reading characters in std::string: array index operator.
	// Regular indexed loop. Can also be adopted to use while and do-while.
	std::cout << "For loop with array index notation" << std::endl;

	std::cout << "str1(for loop): ";
	for (size_t i{ 0 }; i < str1.size(); ++i)
		std::cout << " " << str1[i];
	std::cout << std::endl;

	std::cout << "\n===============================================\n\n";

	// Can also use range based for loop
	std::cout << "Using range based for loop" << std::endl;

	std::cout << "str1(range based for loop): ";
	for (char value : str1)
		std::cout << " " << value;
	std::cout << std::endl;

	std::cout << "\n===============================================\n\n";

	// at() syntax
	std::cout << "Using the std::string::at() method" << std::endl;
	std::cout << "str1(for loop with at()): ";
	for (size_t i{ 0 }; i < str1.size(); ++i)
		std::cout << " " << str1.at(i);
	std::cout << std::endl;

	std::cout << "\n===============================================\n\n";

	// Modifying with operator[] and at()
	std::cout << "Modifying with operator[] and at()" << std::endl;
	str1[0] = 'B';
	str1.at(1) = 'a';
	std::cout << "str1(modified): " << str1 << std::endl;

	std::cout << "\n===============================================\n\n";

	// Getting the front and back characters
	std::string str2{ "The Phoenix King" };
	char front_char = str2.front();
	char back_char = str2.back();
	std::cout << "The front char in str2 is: " << front_char << std::endl;
	std::cout << "The back char in str2 is: " << back_char << std::endl;

	front_char = 'r';
	back_char = 'd';

	std::cout << "str2: " << str2 << std::endl; // Nothing change front_char and back_char are copies

	// Solution use references
	char& front_char_ref = str2.front();
	char& back_char_ref = str2.back();

	front_char_ref = 'r';
	back_char_ref = 'd';

	std::cout << "str2: " << str2 << std::endl;

	std::cout << "\n===============================================\n\n";

	// c_str method
	// https://en.cppreference.com/w/cpp/string/basic_string/c_str
	// Returns const char* to the wrapped string. You shouldn't use it
	// to modify data in the string
	str2 = "The Phoenix King";
	const char* wrapped_c_string = str2.c_str();
	std::cout << "Wrapped c_string: " << wrapped_c_string << std::endl;

	std::cout << "\n===============================================\n\n";

	// data()
	// https://en.cppreference.com/w/cpp/string/basic_string/data
	str2 = "Hello World";

	char* data = str2.data();
	std::cout << "Wrapped c_string: " << data << std::endl;

	data[0] = 'B'; // This is also change original string

	std::cout << "Wrapped c_string (after modification): " << data << std::endl;
	std::cout << "Original string (after modification): " << str2 << std::endl;


	return 0;
}