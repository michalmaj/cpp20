#include <iostream>

int main()
{

	// Declare array
	char message[5]{ 'H', 'e', 'l', 'l', 'o' };

	//Print out the array through looping
	std::cout << "message: ";
	for (auto c : message)
		std::cout << c;
	std::cout << std::endl;

	// Change characters in our array
	message[1] = 'a';

	//Print out the array through looping
	std::cout << "message: ";
	for (auto c : message)
		std::cout << c;
	std::cout << std::endl;

	// Look out for printing directly using std::cout if we don't have a null character 
	std::cout << "message: " << message << std::endl;

	// If a character array is null terminated, it's called as C-string
	char message2[6]{ 'H', 'e', 'l', 'l', 'o', '\0'};

	// Now everything is OK
	std::cout << "message2: " << message2 << std::endl;

	// Deduce the size
	char message3[]{ 'H', 'e', 'l', 'l', 'o', '\0'};
	std::cout << "message3: " << message3 << std::endl;
	std::cout << "sizeof(message3): " << sizeof(message3) << std::endl;

	// Let's compiler put a null character
	char message4[6]{ 'H', 'e', 'l', 'l', 'o'};
	std::cout << "message4: " << message4 << std::endl;
	std::cout << "sizeof(message4): " << sizeof(message4) << std::endl;


	return 0;
}