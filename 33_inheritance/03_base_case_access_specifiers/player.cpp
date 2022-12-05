#include "player.h"


std::ostream& operator<<(std::ostream& out, const Player& p)
{
	out << "Player [Full name: " << p.get_full_name() <<
		", age: " << p.get_age() <<
		", address: " << p.get_address() << "]";

	return out;
}