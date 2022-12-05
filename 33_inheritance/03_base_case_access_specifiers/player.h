#pragma once

#include "person.h"

class Player : public Person
{
	friend std::ostream& operator<<(std::ostream& out, const Player& p);
public:
	Player() = default;
	~Player() = default;

	void play()
	{
		m_full_name = "John Snow"; // Accessible - public
		m_age = 55; // Accessible - protected
		//m_address = "dhjseabfjk;nf"; // Inaccessible - private; Compiler Error
	}
private:
	int m_career_start_year{ 0 };
	double m_salary{ 0.0 };
	int health_factor{ 0 }; // Let's say that it's 0~10
};

