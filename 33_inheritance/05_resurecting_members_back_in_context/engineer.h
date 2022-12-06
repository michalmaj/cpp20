#pragma once

#include "person.h"

class Engineer : private Person
{
	friend std::ostream& operator<<(std::ostream& out, const Engineer& e);
public:
	Engineer() = default;
	~Engineer() = default;

	void build_something()
	{
		m_full_name = "John Snow"; // Accessible - public (but now is private for this class)
		m_age = 23; // Accessible - protected (but now is private for this class)
		//m_address = "9871234-098"; // Inaccessible - private; Compiler Error
	}


protected: // We can resurrect them with any access level as long it isn't a private in Person class, for example methods will be protected
	// These let us to bring back public and protected elements from Person class, so we can use these methods in CivilEngineer class 
	using Person::get_full_name;
	using Person::get_age;
	using Person::get_address;


	int get_contract_count() const
	{
		return contract_count;
	}

public:
	using Person::m_full_name;
	using Person::m_age; // It is protected in Person class.
	//using Person::m_address; // It is private in Person class, so we can't change their visibility; Compiler Error

	using Person::add; // Resurrects an add() function and all overload oh this function.

private:
	int contract_count{ 0 };
};

