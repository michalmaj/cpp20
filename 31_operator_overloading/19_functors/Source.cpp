#include <iostream>
#include <string>
#include <format>

class Print
{
public:
	void operator()(const std::string& name) const
	{
		std::cout << "The name is: " << name << std::endl;
	}

	std::string operator()(const std::string& last_name, const std::string& first_name) const
	{
		return std::format("{} {}", last_name, first_name);
	}
};

void do_something(const Print& printer)
{
	printer("Snow");
}

int main()
{
	Print print;

	print("John");
	do_something(print);

	std::cout << print("Snow", "John") << std::endl;


	return 0;
}