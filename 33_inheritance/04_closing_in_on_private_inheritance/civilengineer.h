#pragma once

#include "engineer.h"

class CivilEngineer : public Engineer
{
	friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& ce);
public:
	CivilEngineer() = default;
	~CivilEngineer() = default;

	void build_road()
	{
		//get_full_name(); // Inaccessible
		//m_full_name = "John Snow"; // Inaccessible
		//m_age = 45; // Inaccessible
	}

private:
	std::string m_speciality{ "None" };
};

