#include "boxcontainer.h"

std::string& modify(std::string& str_param, char(*modifier)(const char&))
{
	for (size_t i{ 0 }; i < str_param.size(); ++i)
		str_param.at(i) = modifier(str_param.at(i)); // Calling the callback

	return str_param;
}

// Modifying a BoxContainer of strings
BoxContainer<std::string>& modify(BoxContainer<std::string>& sentence, char(*modifier)(const char&))
{
	for(size_t i{0}; i < sentence.size(); ++i)
	{
		// COde below relies on get_item() to return a reference
		// Loop through the word modifying each character
		for(size_t j{}; j < sentence.get_item(i).size(); ++j)
		{
			sentence.get_item(i)[j] = modifier(sentence.get_item(i)[j]);
		}
	}
	return sentence;
}

std::string get_best(const BoxContainer<std::string>& sentence, bool(*comparator)(const std::string& str1, const std::string& str2))
{
	std::string best = sentence.get_item(0);
	for(size_t i{1}; i < sentence.size(); ++i)
	{
		if(comparator(sentence.get_item(i), best))
		{
			best = sentence.get_item(i);
		}
	}

	return best;
}

int main()
{
	std::string str{ "Hello" };

	auto encrypt = [](const char& param) {return static_cast<char>(param + 3); }; // Callback function
	auto decrypt = [](const char& param) {return static_cast<char>(param - 3); }; // Callback function

	// Modifying through callbacks
	std::cout << "Initial: " << str << std::endl;
	std::cout << "Encrypted: " << modify(str, encrypt) << std::endl;
	std::cout << "Decrypted: " << modify(str, decrypt) << std::endl;

	std::cout << "\n=========================================================\n\n";

	// Passing lambda function directly
	std::cout << "Initial: " << str << std::endl;
	std::cout << "Encrypted: " << modify(str, [](const char& param) {return static_cast<char>(param + 3); }) << std::endl;
	std::cout << "Decrypted: " << modify(str, [](const char& param) {return static_cast<char>(param - 3); }) << std::endl;

	std::cout << "\n=========================================================\n\n";

	BoxContainer<std::string> quote;
	quote.add("The");
	quote.add("sky");
	quote.add("is");
	quote.add("blue");
	quote.add("my");
	quote.add("friend");

	// Modifying through callbacks
	std::cout << "Initial: " << quote << std::endl;
	std::cout << "Encrypted: " << modify(quote, encrypt) << std::endl;
	std::cout << "Decrypted: " << modify(quote, decrypt) << std::endl;

	std::cout << "\n=========================================================\n\n";

	auto larger_in_size = [](const std::string& str1, const std::string& str2)
	{
		return (str1.size() > str2.size());
	};

	auto greater_lexicographically = [](const std::string& str1, const std::string& str2)
	{
		return (str1 > str2);
	};

	std::cout << "Getting the best:" << std::endl;
	std::cout << "larger in size: " << get_best(quote, larger_in_size) << std::endl;
	std::cout << "greater lexicographically: " << get_best(quote, greater_lexicographically) << std::endl;

	return 0;
}