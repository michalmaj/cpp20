/*
 * We can declare variables inside switch statement. This variable will be visible in all
 * switch scope (so switch can be treat as a one big scope) from place where is declared.
 * We won't see this variable above declaration.
 */

#include <iostream>

int main()
{

	int condition{ 0 };

	// variable data will we accessible from any place inside switch
	switch (int data{ 7 };  condition)
	{
		int x; // we can declare variable here, but we CAN'T initialize it here!!!!
	case 0:
		int y; // same here, declaration OK, initialization BAD (compiler error)
		x = 6;
		x++;
		//z = 6; // We can't use z variable here, declaration is below this line!
		std::cout << "x: " << x << std::endl;
		std::cout << "Statement1" << std::endl;
		std::cout << "Statement2" << std::endl;
		break;

	case 1:
		int z; // same here, declaration OK, initialization BAD (compiler error)
		y = 5;
		std::cout << "y: " << y << std::endl;
		std::cout << "Statement3" << std::endl;
		std::cout << "Statement4" << std::endl;
		break;

	case 2: // if we put our case in braces {}, variable inside will be visible only here
		{
		int k{4}; // we can even initialize with declaration, this variable live only
			      // in this scope
		std::cout << "Statement5" << std::endl;
		std::cout << "Statement6" << std::endl;
		}
		break;

	default:
		int u; // same here, declaration OK, initialization BAD (compiler error)
		z = 10;
		//k = 9; // k is not reachable here 
		std::cout << "z: " << z << std::endl;
		std::cout << "Statement7" << std::endl;
		std::cout << "Statement8" << std::endl;
		break;
	}

	std::cout << "Moving On" << std::endl;



	return 0;
}