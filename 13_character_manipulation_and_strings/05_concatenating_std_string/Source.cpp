#include <iostream>
#include <string>


int main()
{
	// Concatenating two strings: The operator+
	std::cout << std::endl;
	std::cout << "Concatenating two strings operator+" << std::endl;

	std::string str1{ "Hello" };
	std::string str2{ "World" };

	std::string message = str1 + " my " + str2;

	std::cout << "message: " << message << std::endl;

	std::cout << "\n==========================================\n\n";

	// Concatenating string literals: No, No - Compiler Error.
	// String literals are expanded into cont char* arrays and C++ doesn't know
	// how to add arrays with the operator+. Hence the compiler error.
	std::cout << "Concatenating string literals: No, No - Compiler Error." << std::endl;

	//std::string str3{ "Hello" + "World" }; // CE
	//std::string str4 = "Hello" + "World"; // CE

	std::cout << "\n==========================================\n\n";

	// A few ways around for string literal concatenation
	std::cout << "A few ways around for string literal concatenation" << std::endl;

	std::string str5{ "Hello World" }; // Make the string one literal in the first place
	std::string str6{ "Hello" " World" }; // Put the literals side by side without + in between
	std::string str7{ std::string{"Hello"} + " World" }; // Turn one or both into a std::string

	std::cout << "str5: " << str5 << std::endl;
	std::cout << "str6: " << str6 << std::endl;
	std::cout << "str7: " << str7 << std::endl;

	using namespace std::string_literals; // necessary for s suffix
										  // This pollutes the namespace main
	std::string str8{ "Hello"s + " World" }; // Turn one or both into strings using s suffix.
											 // The string_literals has to be imported for this

	std::cout << "str8: " << str8 << std::endl;

	// A better way to not pollute the namespace
	std::string str9;
	{
		using namespace std::string_literals;
		str9 = "Hello"s + " World";
	}
	std::cout << "str9: " << str9 << std::endl;

	std::cout << "\n==========================================\n\n";

	// std::string is a compound type, it has properties and behaviors
	// one of the behaviors is append. We access the behaviors using
	// the dot operator '.' after the std::string variable name.
	std::cout << "Using the append method" << std::endl;
	std::string str10{ "Hello" };
	std::string str11{ " World" };
	std::string str12 = str10.append(str11);

	std::cout << "str12: " << str12 << std::endl;

	std::string str13{ std::string{"Hello"}.append(" World") };

	std::cout << "str13: " << str13 << std::endl;

	std::cout << "\n==========================================\n\n";

	// Append can do more than the operator+
	// The operator+ is just a convenience for basic concatenation
	std::cout << "Append method can do more then operator+" << std::endl;
	std::string str14{ "Hello " };
	std::string str15{ str14.append(5, '?') }; // Appends 5 '?' characters

	std::cout << "str15: " << str15 << std::endl;

	std::string str16{ "The world is our shared home." };
	std::string str17{ "Hello " };
	std::string str18{ str17.append(str16, 4, 5) }; // Append a sub-section of another
															   // string starting from index 4,
															   // 5 characters
	std::cout << "str18: " << str18 << std::endl;

	// Direct output
	std::string str19{ "Hello " };
	std::cout << "Direct output: " << str19.append(str16, 4, 5) << std::endl;

	std::cout << "\n==========================================\n\n";

	// Concatenating strings and characters
	std::cout << "Concatenating strings and characters" << std::endl;
	std::string str20{ "Hello" };
	std::string str21{ "World" };
	std::string str22{ str20 + ' ' + str21 }; // The space in between a character

	std::cout << "str22: " << str22 << std::endl;

	std::string str23 = "Hello";
	// If we don't prioritize with parentheses we will get wrong output comma and space will be
	// treat as ASCII values and after addition we will get single character described by a number
	(str23 += ',') + ' ';
	std::cout << "str23: " << str23 << std::endl;

	// Another solution
	std::string str24{ "Hello" };
	std::string str25{ "I am here to see you." };
	std::string str26{ str24 + ',' + ' ' + str25 };
	std::cout << "str26: " << str26 << std::endl;

	std::cout << "\n==========================================\n\n";

	// Appending C-strings and char arrays
	std::cout << "Appending C-strings and char arrays" << std::endl;
	const char message1[]{ "World" };
	const char* message2{ "World" };

	std::cout << "+ char array: " << std::string{ "Hello " } + message1 << std::endl;
	std::cout << "+ C-String: " << std::string{ "Hello " } + message2 << std::endl;
	std::cout << "append char array: " << std::string{ "Hello" }.append(message1) << std::endl;
	std::cout << "append C-String: " << std::string{ "Hello " }.append(message2) << std::endl;

	std::cout << "\n==========================================\n\n";

	// Concatenating std::string and numbers
	std::cout << "Concatenating std::string and numbers" << std::endl;
	std::string str27{ "Hello" };

	str27 += 67; // Treats 67 as a character code
				 // When using the += operator, C++ knows to treat the integer operand as a character
				 // code and append that to our std::string.
	std::cout << "str27: " << str27 << std::endl; // HelloC - 'C' in ASCII is 67

	// Solution
	str27 = "Hello";
	str27 += std::to_string(67);
	std::cout << "str27: " << str27 << std::endl;

	return 0;
}