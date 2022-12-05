#include "nurse.h"

std::ostream& operator<<(std::ostream& out, const Nurse& n)
{
	out << "Nurse [Full name: " << n.get_full_name() <<
		", age: " << n.get_age() <<
		", address: " << n.get_address() <<
		", practice certificate id: " << n.practice_certificate_id << "]";

	return out;
}