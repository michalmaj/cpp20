#include <iostream>

void f1();
void f2();
void f3();

void exception_thrower()
{
	std::cout << "starting execution_thrower()" << std::endl;
	throw 0; // Execution will halt from here
	std::cout << "ending execution_thrower()" << std::endl;
}

int main()
{
	try
	{
		f1();
	}catch(int& ex)
	{
		std::cout << "Handling execution in main()" << std::endl;
	}

	std::cout << "END" << std::endl;
	return 0;
}

void f1()
{
	std::cout << "Starting f1()" << std::endl;
	try
	{
		f2();
	}
	catch (int& ex)
	{
		std::cout << "Handling execution in f1()" << std::endl;
	}
	std::cout << "Ending f1()" << std::endl;
}
void f2()
{
	std::cout << "Starting f2()" << std::endl;
	try
	{
		f3();
	}
	catch (int& ex)
	{
		std::cout << "Handling execution in f2()" << std::endl;
	}
	std::cout << "Ending f2()" << std::endl;
}
void f3()
{
	std::cout << "Starting f3()" << std::endl;
	try
	{
		exception_thrower();
	}
	catch (int& ex)
	{
		std::cout << "Handling execution in f3()" << std::endl;
	}
	std::cout << "Ending f3()" << std::endl;
}