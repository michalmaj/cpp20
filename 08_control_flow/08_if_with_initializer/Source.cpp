#include <iostream>

int main()
{

	bool go{ false };

	if (int speed{ 10 }; go)
	{
		std::cout << "Speed: " << speed << std::endl;
		if (speed > 5)
			std::cout << "Slow down!\n";
		else
			std::cout << "All good!\n";
	}
	else
	{
		std::cout << "Speed: " << speed << std::endl;
		std::cout << "Stop!\n";
	}

	//// speed variable is visible only in if statement
	//std::cout << "Out of the if block, speed: " << speed << std::endl;

	return 0;
}