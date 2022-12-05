#include "person.h"
#include "player.h"
#include "nurse.h"
#include "engineer.h"


int main()
{
	Person person1{ "Michael Maj", 20, "Blue Sky St 233 #56" };
	std::cout << "person1: " << person1 << std::endl;

	std::cout << "\n=================================\n\n";

	Player player;
	player.m_full_name = "Samuel Jackson"; // Accessible from outside - public
	//player.m_age = 32; // Inaccessible from outside - protected; Compiler Error
	//player.m_address = "ksablfsna"; // Inaccessible from outside - private; Compiler Error

	std::cout << "player: " << player << std::endl;

	std::cout << "\n=================================\n\n";

	Nurse nurse1;
	//nurse1.m_full_name = "Davy Johns"; // Inaccessible from outside - for nurse class it's protected variable
	//nurse1.m_age = 51; // Inaccessible from outside - protected; Compiler Error
	//nurse1.m_addres = "adjamwsif"; // Inaccessible from outside - private; Compiler Error

	std::cout << "nurse1: " << nurse1 << std::endl;

	std::cout << "\n=================================\n\n";

	Engineer engineer1;
	//engineer1.m_full_name = "Olivier Godson"; // Inaccessible from outside - for engineer class it's private variable
	//engineer1.m_age = 43; // Inaccessible from outside - protected; Compiler Error
	//engineer1.m_address = "dflkajfiu"; // Inaccessible from outside - private; Compiler Error

	std::cout << "engineer1: " << engineer1 << std::endl;


	return 0;
}