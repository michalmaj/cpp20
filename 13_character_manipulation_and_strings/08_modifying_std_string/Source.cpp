#include <iostream>
#include <string>

int main()
{

	// Clear: removes all characters from the string
	std::string str1{ "The Lion Dad" };

	std::cout << "str1 is: " << str1 << std::endl;
	std::cout << "str1 size: " << str1.size() << std::endl;
	std::cout << "str1 capacity: " << str1.capacity() << std::endl;

	str1.clear(); // After this line string will be empty

	std::cout << "str1 is: " << str1 << std::endl;
	std::cout << "str1 size: " << str1.size() << std::endl;
	std::cout << "str1 capacity: " << str1.capacity() << std::endl; // still 15

	std::cout << "\n================================================\n\n";

	// Insert character:
	// basic_string& insert(size_type index, size_type count, CharT ch);
	// Inserts count characters int the string starting at index index

	std::string str2{ "123" };
	std::cout << "str2 is: " << str2 << std::endl;

	str2.insert(1, 1, '3'); // Insert one element '3' at index 1.

	std::cout << "str2 is: " << str2 << std::endl; // 1323

	str2.insert(0, 2, '7'); // We can for example insert more than one at once.
										  // This time in index 0 we will insert two '7'.

	std::cout << "str2 is: " << str2 << std::endl; // 771323

	std::cout << "\n================================================\n\n";

	// Insert C-string
	// basic_string& insert(size_type index, size_type count, CharT* ch);
	// Inserts null-terminated character string pointed to by s
	// at the position index. The length of the string is determined
	// by the first null character

	std::string str3{ "Hello!" };
	const char* txt3{ " World" };

	std::cout << "str3 is: " << str3 << std::endl;

	str3.insert(5, txt3);

	std::cout << "str3 is: " << str3 << std::endl;

	std::cout << "\n================================================\n\n";

	// Insert part of a C-string
	// basic_string& insert(size_type index, CharT* ch, size_type count);
	// Inserts the characters in the range [s, s+count) at the position index.
	// The range can contain null characters.

	std::string str4{ "Hello!" };
	const char* txt4{ " World Health Organization" };

	std::cout << "str4 is: " << str4 << std::endl;

	str4.insert(5, txt4, 6);

	std::cout << "str4 is: " << str4 << std::endl;

	std::cout << "\n================================================\n\n";

	// Insert std::string
	// basic_string& insert(size_type index, const basic_string& str);
	// Inserts string str at the position index

	std::string str5{ " World" };
	std::string str6{ "Hello!" };

	std::cout << "str6 is: " << str6 << std::endl;

	str6.insert(5, str5);
	std::cout << "str6 is: " << str6 << std::endl;

	std::cout << "\n================================================\n\n";

	// Insert part of a std::string
	// basic_string& insert(size_type index, const basic_string& str, size_type index_str,
	//						size_type count = npos);
	// Inserts a string, obtained by str.substr(index_str, count) at the position index

	std::string str7{ "Hello!" };
	std::string str8{ "Statistical Analysis of the World Population" };

	std::cout << "str7 is: " << str7 << std::endl;

	str7.insert(5, str8, 27, 6); // Start from index in str8 and take 6 characters

	std::cout << "str7 is: " << str7 << std::endl;

	std::cout << "\n================================================\n\n";

	// Erase
	// basic_string& erase(size_type index = 0, size_type count = npos);
	// Starting at index index, erase count characters from the string.
	// Notice that this function returns a reference

	std::string str9{ "Hello World is a message used to start off things when learning programming!" };

	std::cout << "str9 is: " << str9 << std::endl;

	str9.erase(11, str9.size() - 12);

	std::cout << "str9 is: " << str9 << std::endl;

	// Reset str9
	str9 = "Hello World is a message used to start off things when learning programming!";

	std::cout << "str9: " << str9.erase(11, str9.size() - 12) << std::endl;

	std::cout << "\n================================================\n\n";

	// push_back
	// void push_back(CharT ch);
	// Appends the given character ch to the end of the string
	std::string str10{ "Hello World!" };
	str10.push_back('!');
	std::cout << "str10 is: " << str10 << std::endl;

	// pop_back
	// void pop_back();
	// Removes the last character from the string.
	std::string str11{ "Hello World" };
	str11.pop_back();
	std::cout << "str11 is: " << str11 << std::endl;

	return 0;
}