#pragma once

#include "person.h"

class Engineer : private Person
{
	friend std::ostream& operator<<(std::ostream& out, const Engineer& e);
public:
	Engineer() = default;
	~Engineer() = default;

	int get_contract_count() const
	{
		return contract_count;
	}

	void build_something()
	{
		m_full_name = "John Snow"; // Accessible - public (but now is private for this class)
		m_age = 23; // Accessible - protected (but now is private for this class)
		//m_address = "9871234-098"; // Inaccessible - private; Compiler Error
	}

private:
	int contract_count{ 0 };
};

