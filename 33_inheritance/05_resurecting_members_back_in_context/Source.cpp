#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

int main()
{
	Engineer engineer;
	engineer.m_age = 55;
	std::cout << "engineer: " << engineer << std::endl;

	CivilEngineer civil_engineer;
	civil_engineer.build_road();
	std::cout << "civil_engineer: " << civil_engineer << std::endl;

	return 0;
}