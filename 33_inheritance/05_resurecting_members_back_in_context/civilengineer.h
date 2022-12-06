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
		get_full_name(); // Works
		m_full_name = "John Snow"; // Works
		m_age = 45; // Works

		add(10, 2);
		add(10, 20, 30);
	}

	//using Person::do_something; // We can't resurrect something that was eclipsed in class that is higher in hierarchy. 

private:
	std::string m_speciality{ "None" };
};

