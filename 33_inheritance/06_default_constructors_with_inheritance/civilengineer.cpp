#include "civilengineer.h"


std::ostream& operator<<(std::ostream& out, const CivilEngineer& ce)
{
	out <<
		"Civil Engineer [Full name: " << ce.get_full_name() << // Now work 
		", age: " << ce.get_age() << // Now work
		", address: " << ce.get_address() << // Now work
		", contract count: " << ce.get_contract_count() << // Accessible - it's public in Engineer class
		", speciality: " << ce.m_speciality << "]";

	return out;
}

CivilEngineer::CivilEngineer()
{
	std::cout << "Default constructor for CivilEngineer called..." << std::endl;
}
