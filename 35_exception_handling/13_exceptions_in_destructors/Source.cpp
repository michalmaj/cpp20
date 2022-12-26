#include <iostream>

class Item
{
public:
	Item() = default;
	// Destructor is noexcept by default, but we can disable this feature 
	~Item() noexcept(false)
	{
		try
		{
			throw 0;
		}
		catch (int ex)
		{
			throw;
		}
	}
};

int main()
{
	try
	{
		Item item;
	}
	catch (int ex)
	{
		std::cout << "main(): catching int exception" << std::endl;
	}

	return 0;
}