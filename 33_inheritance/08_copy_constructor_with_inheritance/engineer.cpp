#include "engineer.h"


std::ostream& operator<<(std::ostream& out, const Engineer& e)
{
	out << "Engineer [Full name: " << e.get_full_name() <<
		", age: " << e.get_age() <<
		", address: " << e.get_address() <<
		", contract count: " << e.contract_count << "]";

	return out;
}

Engineer::Engineer()
{
	std::cout << "Default constructor for Engineer called..." << std::endl;
}

Engineer::Engineer(std::string_view fullname, int age, std::string_view address, int contract_count)
	: Person(fullname, age, address), contract_count(contract_count)
{
	std::cout << "Custom constructor for Engineer called..." << std::endl;
}

Engineer::Engineer(const Engineer& source)
	: Person(source), contract_count(source.contract_count)
{
	std::cout << "Copy constructor for Engineer called..." << std::endl;
}