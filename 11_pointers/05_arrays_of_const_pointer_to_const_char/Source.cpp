#include <iostream>

int main()
{
	const char* students[]
	{
		"Arthur Dayne",
		"Barristan Selmy",
		"Jaime Lannister",
		"Arya Stark",
		"Jon Snow",
		"Syrio Forel",
	};

	// Print out the students
	std::cout << std::endl;
	std::cout << "Printing out the students:" << std::endl;
	for(const char* student : students)
	{
		std::cout << student << std::endl;
	}

	std::cout << "\n===============================================\n\n";

	// Print first letter of the first student
	std::cout << students[0][0] << std::endl << std::endl;;

	// We can't modify this value
	//*students[0][0] = 'B'; // CE

	// But it is possible to create new student and replace in out students array
	const char* new_student{ "Bob the Great" };
	students[0] = new_student;

	for (const char* student : students)
	{
		std::cout << student << std::endl;
	}

	std::cout << "\n===============================================\n\n";

	// To prevent that we need to create array as const pointer to const
	const char* const students1[]
	{
		"Arthur Dayne",
		"Barristan Selmy",
		"Jaime Lannister",
		"Arya Stark",
		"Jon Snow",
		"Syrio Forel",
	};

	for (const char* student : students1)
	{
		std::cout << student << std::endl;
	}

	const char* new_student1{ "Bob the Great" };
	//students1[0] = new_student1; // Right now is a compiler error

	return 0;
}