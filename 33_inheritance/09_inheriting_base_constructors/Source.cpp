#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

int main()
{
	Engineer engineer1;
	std::cout << "engineer1: " << engineer1 << std::endl;

	Engineer engineer2{ "Daniel Gray", 23, "Green Sky Oh Blue 33St#75" };
	std::cout << "engineer2: " << engineer2 << std::endl;

	//Engineer engineer3{ "Daniel Gray", 23, "Green Sky Oh Blue 33St#75", 76 }; // Now we only have constructors inherit from Person class, there is no 4 parameters constructor

	// After uncomment our Engineer 4 params constructor we can use 
	Engineer engineer4{ "Daniel Gray", 23, "Green Sky Oh Blue 33St#75", 76 };
	std::cout << "engineer4: " << engineer4 << std::endl;

	Engineer engineer5;
	std::cout << "engineer1: " << engineer1 << std::endl;


	return 0;
}