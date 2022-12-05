#pragma once

#include "person.h"

class Nurse : protected Person
{
	friend std::ostream& operator<<(std::ostream& out, const Nurse& n);
public:
	Nurse() = default;
	~Nurse() = default;

	void treat_unwell_person()
	{
		m_full_name = "John Snow"; // Accessible - public (but now is protected for this class)
		m_age = 23; // Accessible - protected (but now is protected for this class)
		//m_address = "9871234-098"; // Inaccessible - private; Compiler Error
	}
private:
	int practice_certificate_id{ 0 };
};

