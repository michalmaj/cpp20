#pragma once

#include <iostream>
#include <string>
#include <string_view>

class Dog
{
public:
	Dog() = default;
	Dog(const std::string& name_param, const std::string& breed_param, unsigned int age_param);

	// Getters that works as setters
	std::string& name();
	std::string& breed();
	unsigned int& age();

	// To make them work with const objects
	// We need to set up overloading based on const
	const std::string& name() const;
	const std::string& breed() const;
	const unsigned int& age() const ;

	// Utility functions
	void print_info() const;

private:
	std::string m_name;
	std::string m_breed;
	unsigned int m_age;
};

