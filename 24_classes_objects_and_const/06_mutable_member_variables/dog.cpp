#include "dog.h"


Dog::Dog(const std::string& name_param, const std::string& breed_param, unsigned int age_param)
{
	m_name = name_param;
	m_breed = breed_param;
	m_age = age_param;
}

// Getters
std::string& Dog::name()
{
	return m_name;
}
std::string& Dog::breed()
{
	return m_breed;
}
unsigned int& Dog::age()
{
	return m_age;
}

// To make them work with const objects
// We need to set up overloading based on const
const std::string& Dog::name() const
{
	return m_name;
}
const std::string& Dog::breed() const
{
	return m_breed;
}
const unsigned int& Dog::age() const
{
	return m_age;
}

// Utility functions
void Dog::print_info() const
{
	++m_print_info_count; // Variable is marked as mutable, so we can modify it even inside const method!
	std::cout << "Dog (" << this << ") : [ name : " << this->m_name
		<< ", breed : " << this->m_breed
		<< ", age : " << this->m_age
		<< ", print_count : " << m_print_info_count << "]" << std::endl;
}