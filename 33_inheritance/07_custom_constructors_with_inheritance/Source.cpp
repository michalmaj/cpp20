#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

int main()
{
	Person person1{ "John Snow", 27, "Winterfall Cold 33St#75" };
	std::cout << "person1: " << person1 << std::endl;

	std::cout << "\n======================================\n\n";

	Engineer engineer1{ "Daniel Gray", 41, "Green Sky Oh Blue 33St#75", 12 };
	std::cout << "engineer1: " << engineer1 << std::endl;

	std::cout << "\n======================================\n\n";

	CivilEngineer civil_engineer1{ "John Travolta", 51, "Tiny Dog 42St#89", 31, "Road Strength" };
	std::cout << "civil_engineer1: " << civil_engineer1 << std::endl;

	return 0;
}