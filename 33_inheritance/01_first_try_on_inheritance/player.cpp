#include "player.h"



std::ostream& operator<<(std::ostream& out, const Player& p)
{
	out << "Player [game: " << p.m_game << " name: " << p.get_first_name() << " " << p.get_last_name() << "]";

	return out;
}

Player::Player(std::string_view game_param)
	: m_game(game_param)
{}
