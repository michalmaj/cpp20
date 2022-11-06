#include "person.h"

// Constructors
Person::Person(std::string_view last_name_param, std::string_view first_name_param, int age_param)
	: last_name(last_name_param), first_name(first_name_param), age(new int(age_param))
{}

Person::Person(std::string_view last_name_param, std::string_view first_name_param)
	: Person(last_name_param, first_name_param, 0)
{}

Person::Person(std::string_view last_name_param)
	: Person(last_name_param, "")
{}

// Copy constructor
//Person::Person(const Person source_p)
//	: last_name(source_p.get_last_name()),
//      first_name(source_p.get_first_name()),
//	  age(source_p.get_age())
//{}

//Person::Person(const Person& source_p)
//	: last_name(source_p.get_last_name()),
//      first_name(source_p.get_first_name()),
//	  age(source_p.get_age()) // We need to avoid blindly copying the pointer
//{
//	std::cout << "Copy constructor called\n";
//}

//// Properly created copy constructor
//Person::Person(const Person& source_p)
//	: last_name(source_p.get_last_name()),
//	  first_name(source_p.get_first_name()),
//	  age(new int(*(source_p.get_age())))
//{
//	std::cout << "Copy constructor called\n";
//}

// We can also use a delegating constructor for Copy Constructor
Person::Person(const Person& source_p)
	: Person(source_p.get_last_name(), source_p.get_first_name(), *(source_p.get_age()))
{
	std::cout << "Copy constructor called\n";
}


// Destructor
Person::~Person()
{
	delete age; // Make sure that we are not leaking memory
}