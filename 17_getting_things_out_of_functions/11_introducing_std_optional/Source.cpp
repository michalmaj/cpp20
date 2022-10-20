#include <iostream>
#include <optional>



int main()
{
	// Declare and initialize
	std::optional<int> items{ 3 };
	std::optional<std::string> name{ "Michal Maj" };
	std::optional<double> weight{ 77.2 };
	std::optional<char> character{ 's' };

	// Declare and empty initialize
	std::optional<std::string> dog_name{}; // Initialize to std::nullopt
	std::optional<int> age{ std::nullopt }; // std::nullopt is the null or zero equivalent
											// for std::optional
	std::optional<char> letter = std::nullopt; // Triggers unused warning
	std::optional<double> height = {}; // Initialize to std::nullopt, it triggers unused warning

	// Read from an std::optional variable
	std::cout << "items: " << items.value() << std::endl;
	std::cout << "items: " << *items << std::endl; // This may be confusing as it's not a pointer

	std::cout << "name: " << name.value() << std::endl;
	std::cout << "weight: " << weight.value() << std::endl;
	std::cout << "character: " << character.value() << std::endl;

	// Write to std::optional
	dog_name = "Fluffy";
	age = 26;

	std::cout << "dog name: " << dog_name.value() << std::endl;
	std::cout << "age: " << age.value() << std::endl;

	//// Reading bad data
	//std::cout << letter.value() << std::endl; // Throws exception and crashes program
	//std::cout << height.value() << std::endl; // Trhows exception and crashes program

	// has_value
	std::cout << std::boolalpha;
	std::cout << "letter.has_value(): " << letter.has_value() << std::endl;
	std::cout << "height.has_value(): " << height.has_value() << std::endl;
	std::cout << "dog_name.has_value(): " << dog_name.has_value() << std::endl;

	std::cout << std::endl;
	std::cout << "Conditional reading" << std::endl;
	// Do your checks before you read data
	if (letter.has_value())
		std::cout << "letter contains a useful value" << std::endl;
	else
		std::cout << "letter contains std::nullopt" << std::endl;

	// Checking against std::nullopt
	if(letter != std::nullopt)
		std::cout << "letter contains a useful value" << std::endl;
	else
		std::cout << "letter contains std::nullopt" << std::endl;

	return 0;
}