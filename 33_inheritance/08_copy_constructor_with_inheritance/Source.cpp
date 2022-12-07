#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"


int main()
{
	Engineer engineer1{ "Daniel Gray", 41, "Green Sky Oh Blue 33St#75", 12 };

	Engineer engineer2{ engineer1 };

	std::cout << "engineer2: " << engineer2 << std::endl;

	

	return 0;
}