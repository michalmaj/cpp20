#include <iostream>
#include <coroutine>
#include <cassert>
#include "unique_generator.h"

unique_generator<int> generate_numbers()
{
	std::cout << "generate_numbers starting" << std::endl;

	co_yield 10; // return 10 and pauses
	std::cout << "After stop point #1" << std::endl;

	co_yield 20; // return 20 and pauses
	std::cout << "After stop point #2" << std::endl;

	co_yield 30; // return 30 and pauses
	std::cout << "After stop point #3" << std::endl;

	std::cout << "generate_numbers ending" << std::endl;
}

unique_generator<int> infinite_number_stream(int start = 0)
{
	auto value = start;
	for (int i{ 0 };; ++i)
	{
		//std::cout << "In infinite_number stream..." << std::endl;
		co_yield value;
		++value;
	}
}

unique_generator<int> range(int first, int last)
{
	while (first < last)
	{
		co_yield first++;
	}
}

int main()
{
	auto task1 = generate_numbers();

	for (auto i = task1.begin(); i != task1.end(); ++i)
	{
		std::cout << "value: " << *i << std::endl;
	}

	//std::cout << "value: " << task1() << std::endl;
	//std::cout << std::endl;

	//std::cout << "value: " << task1() << std::endl;
	//std::cout << std::endl;

	//std::cout << "value: " << task1() << std::endl;
	//std::cout << std::endl;

	//std::cout << "value: " << task1() << std::endl;
	//std::cout << std::endl;

	//std::cout << std::boolalpha << "coro done: " << task1.m_handle.done() << std::endl;

	std::cout << "\n==========================================\n\n";

	auto task2 = infinite_number_stream();

	for (int i{ 0 }; i < 100; ++i)
		std::cout << "value: " << task2() << std::endl;
	std::cout << std::endl;

	std::cout << "\n==========================================\n\n";

	// Range
	auto task3 = range(0, 25);

	while (true)
	{
		if (task3.is_done())
			break;
		std::cout << task3() << std::endl;
	}


	std::cout << "Done!" << std::endl;


	return 0;
}