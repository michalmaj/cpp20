#include "civilengineer.h"


std::ostream& operator<<(std::ostream& out, const CivilEngineer& ce)
{
	//out << 
	//	//"Civil Engineer [Full name: " << ce.get_full_name() << // Inaccessible - Engineer class uses private inheritance from Person class 
	//	//", age: " << ce.get_age() << // Inaccessible - Engineer class uses private inheritance from Person class
	//	//", address: " << ce.get_address() << // Inaccessible - Engineer class uses private inheritance from Person class
	//	", contract count: " << ce.get_contract_count() << // Accessible - it's public in Engineer class
	//	", speciality: " << ce.m_speciality << "]";

	return out;
}