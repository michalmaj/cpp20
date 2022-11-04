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
	std::cout << "Dog (" << this << ") : [ m_name : " << this->m_name
		<< ", m_breed : " << this->m_breed
		<< ", m_age : " << this->m_age << "]" << std::endl;
}