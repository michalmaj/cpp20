#include <iostream>
#include "boxcontainer.h"

// Callback function
char encrypt(const char& param)
{
	return static_cast<char>(param + 3);
}

// Callback function
char decrypt(const char& param)
{
	return static_cast<char>(param - 3);
}

using char_modifier = char(*)(const char&);
std::string& modify(std::string& str_param, char_modifier modifier)
{
	for (size_t i{ 0 }; i < str_param.size(); ++i)
		str_param.at(i) = modifier(str_param.at(i)); // Calling the callback

	return str_param;
}

// Modifying a BoxContainer of strings
BoxContainer<std::string>& modify(BoxContainer<std::string>& sentence, char(*modifier)(const char&))
{
	for (size_t i{ 0 }; i < sentence.size(); ++i)
	{
		// Code below relies on gte_item() method to return a reference
		// Loop through the word modifying each character
		for (size_t j{ 0 }; j < sentence.get_item(i).size(); ++j)
		{
			sentence.get_item(i)[j] = modifier(sentence.get_item(i)[j]);
		}
	}

	return sentence;
}

//// Type alias - typedef syntax, NOT RECOMMENDED
//typedef bool(*str_comparator)(const std::string& str1, const std::string& str2);

// Type alias - using syntax, better
using str_comparator = bool(*)(const std::string& str1, const std::string& str2);

std::string get_best(const BoxContainer<std::string>& sentence, str_comparator comparator)
{
	std::string best = sentence.get_item(0);
	for (size_t i{ 0 }; i < sentence.size(); ++i)
	{
		if (comparator(sentence.get_item(i), best))
		{
			best = sentence.get_item(i);
		}
	}

	return best;
}

bool larger_in_size(const std::string& str1, const std::string& str2)
{
	return (str1.size() > str2.size()) ? true : false;
}

bool greater_lexicographically(const std::string& str1, const std::string& str2)
{
	return (str1 > str2);
}

int main()
{
	std::cout << "A encrypted: " << encrypt('A') << std::endl;
	std::cout << "D decrypted: " << decrypt('D') << std::endl;

	std::cout << "\n=========================================\n\n";

	std::string msg{ "Hello" };

	std::string outcome = modify(msg, encrypt);
	std::cout << "Outcome: " << outcome << std::endl;

	msg = "Hello";
	outcome = modify(msg, decrypt);
	std::cout << "Outcome: " << outcome << std::endl;

	std::cout << "\n=========================================\n\n";

	BoxContainer<std::string> quote;
	quote.add("The");
	quote.add("sky");
	quote.add("is");
	quote.add("blue");
	quote.add("my");
	quote.add("friend");
	std::cout << "Initial : " << quote << std::endl;
	std::cout << "Encrypted : " << modify(quote, encrypt) << std::endl;
	std::cout << "Decrypted : " << modify(quote, decrypt) << std::endl;

	std::cout << "\n=========================================\n\n";

	str_comparator callback{ larger_in_size };

	std::cout << "larger in size: " << get_best(quote, callback) << std::endl;
	std::cout << "greater lexicographically: " << get_best(quote, greater_lexicographically) << std::endl;


	return 0;
}