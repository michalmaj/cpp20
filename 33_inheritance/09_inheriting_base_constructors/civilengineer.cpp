//#include "civilengineer.h"
//
//std::ostream& operator<<(std::ostream& out, const CivilEngineer& ce)
//{
//	out <<
//		"Civil Engineer [Full name: " << ce.get_full_name() << // Now work 
//		", age: " << ce.get_age() << // Now work
//		", address: " << ce.get_address() << // Now work
//		", contract count: " << ce.get_contract_count() << // Accessible - it's public in Engineer class
//		", speciality: " << ce.m_speciality << "]";
//
//	return out;
//}
//
//CivilEngineer::CivilEngineer()
//{
//	std::cout << "Default constructor for CivilEngineer called..." << std::endl;
//}
//
//
//CivilEngineer::CivilEngineer(std::string_view fullname, int age, std::string_view address, int contract_count, std::string_view speciality)
//	: Engineer(fullname, age, address, contract_count), m_speciality(speciality)
//{
//	std::cout << "Custom constructor for CivilEngineer called..." << std::endl;
//}
//
//CivilEngineer::CivilEngineer(const CivilEngineer& source)
//	: Engineer(source), m_speciality(source.m_speciality)
//{
//	std::cout << "Copy constructor for CivilEngineer called..." << std::endl;
//}