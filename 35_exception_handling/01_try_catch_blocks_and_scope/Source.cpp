#include <iostream>
#include <memory>

class Item
{
public:
	Item()
	{
		std::cout << "Item constructor called" << std::endl;
	}
	~Item()
	{
		std::cout << "Item destructor called" << std::endl;
	}
};

class MyException
{
public:
	MyException() = default;
	MyException(const MyException& ex) = default;
	//MyException(const MyException& ex) = delete;

private:
	//MyException(const MyException& ex) = default;
};

int main()
{
	// Showing that that automatic local variables are destroyed when
	// we are thrown out of a try block
	int a{ 10 };
	int b{ 0 };

	/*
	 * When exception is thrown, control immediately exits the try block.
	 * An automatic local variables are released,
	 * but pointer may leak memory
	 */
	try
	{
		Item item;
		if (b == 0)
			throw 0;

		a++;
		b++;
		std::cout << "Code that executes when things are fine" << std::endl;
	}catch (int ex)
	{
		std::cout << "Something went wrong. Exception thrown: " << ex << std::endl;
	}


	std::cout << "\n===========================================\n\n";

	/*
	 * Throwing a pointer: recipe for disaster.
	 * Throwing pointers is a recipe for disaster, as by the time
	 * the catch block executes, the memory allocated and used in try
	 * block is pointing to invalid data. The program may seem to work
	 * sometimes but there are no guarantees you'll always get valid
	 * stuff if you dereference pointer allocated in the try block.
	 */
	int c{ 0 };
	try
	{
		int var{ 55 };
		int* int_ptr = &var;
		if (c == 0)
			throw int_ptr;
		std::cout << "Keep going other things..." << std::endl;
	}catch (int* ex)
	{
		std::cout << "Something went wrong. Exception thrown: " << *ex << std::endl;
	}

	std::cout << "\n===========================================\n\n";

	// Potential memory leaks
	// The destructor for Item is never called when we're throw out of
	// the try block, and memory is leaked
	int d{ 0 };
	try
	{
		Item* item_ptr = new Item(); // For this destructor won't be called
		std::unique_ptr<Item> item_smart_ptr = std::make_unique<Item>(); // But for this will be called
		if (d == 0)
			throw 0;
		std::cout << "Keep going other things..." << std::endl;
		delete item_ptr;
	}catch (int ex)
	{
		std::cout << "Something went wrong. Exception thrown: " << ex << std::endl;
	}

	std::cout << "\n===========================================\n\n";

	//// Crash our program on purpose
	//throw 0; // Unhandled exception
	//std::cout << "Doing something after we throw" << std::endl;
	
	std::cout << "\n===========================================\n\n";

	// If copy constructor is either deleted, protected or private, the
	// object can't be thrown as exception. We'll get a compiler error.

	try
	{
		MyException e;
		throw e;
	}catch (MyException ex)
	{
		
	}

	std::cout << "Done!" << std::endl;


	return 0;
}