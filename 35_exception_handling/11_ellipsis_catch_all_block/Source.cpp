#include <iostream>
#include "exceptions.h"

void some_function(size_t i)
{
	if (i == 0)
		throw 1;

	if (i == 2)
		throw "const char* - Hello There";

	if (i == 3)
		throw CriticalError("Something is wrong");

	if (i == 4)
		throw std::string("std::string - Hello There");

	
}

int main()
{
	try
	{
		for(size_t i{}; i < 5; ++i)
		{
			try
			{
				some_function(i);
			}
			catch (int ex)
			{
				std::cout << "int handler - caught an integer" << std::endl;
			}
			catch (...)
			{
				std::cout << "Inner... handler, caught some exceptions" << std::endl;
				throw;
			}
		}
	}
	catch (const std::string& ex)
	{
		std::cout << "Caught some string exception" << std::endl;
	}
	catch (...)
	{
		std::cout << "Outer... handler, caught some exceptions" << std::endl;
	}

	return 0;
}