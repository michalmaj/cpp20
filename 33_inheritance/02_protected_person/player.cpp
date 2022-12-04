#include "player.h"



std::ostream& operator<<(std::ostream& out, const Player& p)
{
	out << "Player [game: " << p.m_game << " name: " << p.get_first_name() << " " << p.get_last_name() << "]";

	return out;
}

Player::Player(std::string_view game_param, std::string_view first_name_param, std::string_view last_name_param)
	: m_game(game_param)
{
	first_name = first_name_param;
	last_name = last_name_param;
}
