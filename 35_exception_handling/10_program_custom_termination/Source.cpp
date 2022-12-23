#include <iostream>
#include <exception>
#include <chrono>
#include <thread>

void our_terminate_function()
{
	std::cout << "Our custom terminate function called" << std::endl;
	std::cout << "Program will terminate is 5s..." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::abort(); // This will kill our program
}

int main()
{
	//// normal function
	//std::set_terminate(&our_terminate_function);

	// Lambda function
	std::set_terminate([]()
	{
		std::cout << "Our custom terminate function called" << std::endl;
		std::cout << "Program will terminate is 3s..." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::abort(); // This will kill our program
	});

	throw 1;

	return 0;
}