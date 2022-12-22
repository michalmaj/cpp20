#include <iostream>

void exception_thrower()
{
	throw 'z';
}

void some_function()
{
	for(size_t i{0}; i < 15; ++i)
	{
		std::cout << "Iteration: " << i << std::endl;

		// Outer try block
		// Exceptions thrown in this scope are
		// handled in outer catch blocks
		try
		{
			if (i == 2)
				throw "exception for int 2 thrown"; // Throws const char*

			// Inner try block
			try
			{
				if (i == 5)
					throw 'd'; // Throw char, will be handled by inner catch block

				if (i == 7)
					throw i; // Thrown as size_t, will be handled in outer block

				if (i == 8)
					exception_thrower();

				if (i == 9)
					throw std::string("string thrown for int 9"); // Inner and outer catch blocks can't handle it,
																	   // may be handled by try block wrapping around the function
			}
			catch (char ex) // Inner catch
			{
				std::cout << "Inner catch(char) block: caught thrown for " << ex << std::endl;
			}
		}
		catch (const char* ex) // Outer catch
		{
			std::cout << "Outer catch(const char*) block: caught thrown for " << ex << std::endl;
		}
		catch(size_t ex) // Outer catch
		{
			std::cout << "Outer catch(size_t) block: caught thrown for " << ex << std::endl;
		}
	}
}

int main()
{
	try
	{
		some_function();
	}
	catch (std::string& ex)
	{
		std::cout << "Main function catch(std::string) block: caught thrown for " << ex << std::endl;
	}
	return 0;
}