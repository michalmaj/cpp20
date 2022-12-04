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
	Player(std::string_view game_param);
	~Player() = default;


private:
	std::string m_game{ "None" };
};

