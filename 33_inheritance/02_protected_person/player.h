#pragma once

#include <iostream>
#include <string>
#include <string_view>

#include "person.h"

class Player : public Person
{
	friend std::ostream& operator<<(std::ostream& out, const Player& p);

public:
	Player() = default;
	Player(std::string_view game_param, std::string_view first_name_param, std::string_view last_name_param);
	~Player() = default;


private:
	std::string m_game{ "None" };
};

