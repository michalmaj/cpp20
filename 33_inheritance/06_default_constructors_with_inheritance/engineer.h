#pragma once

#include "person.h"

class Engineer : public Person
{
	friend std::ostream& operator<<(std::ostream& out, const Engineer& e);
public:
	Engineer();
	~Engineer() = default;

	void build_something()
	{
		m_full_name = "John Snow"; // Accessible - public (but now is private for this class)
		m_age = 23; // Accessible - protected (but now is private for this class)
		//m_address = "9871234-098"; // Inaccessible - private; Compiler Error
	}

	int get_contract_count() const
	{
		return contract_count;
	}


private:
	int contract_count{ 0 };
};

