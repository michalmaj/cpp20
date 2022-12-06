#pragma once

#include "engineer.h"

class CivilEngineer : public Engineer
{
	friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& ce);
public:
	CivilEngineer();
	~CivilEngineer() = default;

	void build_road()
	{
		get_full_name();
		m_full_name = "John Snow";
		m_age = 45;

		add(10, 2);
		add(10, 20, 30);
	}



private:
	std::string m_speciality{ "None" };
};

