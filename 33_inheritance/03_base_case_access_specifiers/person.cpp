#include "person.h"


std::ostream& operator<<(std::ostream& out, const Person& p)
{
	out << "Person [Full name: " << p.get_full_name() <<
		", age: " << p.get_age() <<
		", address: " << p.get_address() << "]";
	return out;
}

Person::Person(std::string_view fullname, int age, std::string_view address)
	: m_full_name(fullname), m_age(age), m_address(address)
{}