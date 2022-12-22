#include <iostream>
#include <string_view>

class SomethingIsWrong
{
public:
	SomethingIsWrong(std::string_view s) : m_message(s){}

	// Copy constructor
	SomethingIsWrong(const SomethingIsWrong& source)
	{
		std::cout << "Copy constructor for SomethingIsWrong called" << std::endl;
		m_message = source.m_message;
	}

	// Destructor
	~SomethingIsWrong()
	{
		std::cout << "SomethingIsWrong destructor called" << std::endl;
	}

	std::string_view what() const
	{
		return m_message;
	}

private:
	std::string_view m_message;
};

void do_something(size_t i)
{
	if (i == 2)
		throw SomethingIsWrong("i is 2");
	std::cout << "Doing something at iteration: " << i << std::endl;
}

int main()
{
	for(size_t i{0}; i < 5; ++i)
	{
		try
		{
			do_something(i);
		}
		catch (SomethingIsWrong& ex)
		{
			std::cout << "Exception caught: " << ex.what() << std::endl;
		}
	}

	return 0;
}