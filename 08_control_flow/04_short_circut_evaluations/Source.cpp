#include <iostream>

bool car()
{
	std::cout << "car function running\n";
	return true;
}

bool house()
{
	std::cout << "house function running\n";
	return false;
}

bool job()
{
	std::cout << "job function running\n";
	return true;
}

bool spouse()
{
	std::cout << "spouse function running\n";
	return true;
}

int main()
{
	bool a{ true };
	bool b{ true };
	bool c{ true };
	bool d{ false };

	bool p{ false };
	bool q{ false };
	bool r{ false };
	bool m{ true };

	// AND: if one of the operands is 0, the result is 0
	std::cout << std::endl;
	std::cout << "And short circuit" << std::endl;
	bool result = a && b && c && d;
	std::cout << "result: " << std::boolalpha << result << std::endl;

	// OR: if one of the operands is 1, the result is 1
	std::cout << std::endl;
	std::cout << "OR short circuit" << std::endl;
	result = a or b or c or d;
	std::cout << "result: " << std::boolalpha << result << std::endl;

	std::cout << "\n=======================" << std::endl;

	if (car() and house() and job() and spouse())
		std::cout << "I am happy\n";
	else
		std::cout << "I am sad\n";

	std::cout << "\n=======================" << std::endl;

	if (car() || house() || job() || spouse())
		std::cout << "I am happy\n";
	else
		std::cout << "I am sad\n";

	return 0;
}