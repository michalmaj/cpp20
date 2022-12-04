#include "person.h"


std::ostream& operator<<(std::ostream& out, const Person& p)
{
	out << "Person [" << p.first_name << " " << p.last_name << "]";
	return out;
}

Person::Person(){}
Person::Person(std::string_view first_name_param, std::string_view last_name_param)
	: first_name(first_name_param), last_name(last_name_param)
{}