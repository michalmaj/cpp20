#pragma once

#include <iostream>
#include <string>
#include <string_view>

class Person
{
	friend std::ostream& operator<<(std::ostream& out, const Person& p);

public:
	Person();
	Person(std::string_view first_name_param, std::string_view last_name_param);
	~Person() = default;

	// Getters
	std::string get_first_name() const { return first_name; }
	std::string get_last_name() const { return last_name; }

	// setters
	void set_first_name(std::string_view first_name_param)
	{
		first_name = first_name_param;
	}

	void set_last_name(std::string_view last_name_param)
	{
		last_name = last_name_param;
	}


private:
	std::string first_name{ "Mysterious" };
	std::string last_name{ "Person" };
};

