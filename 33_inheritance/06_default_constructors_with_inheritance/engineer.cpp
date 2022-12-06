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
