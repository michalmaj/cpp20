#include <iostream>

namespace NO_ADJUST
{
	double add(double x, double y)
	{
		return x + y;
	}
}

namespace ADJUST
{
	constexpr double adjustment{ 0.724 };
	double add(double x, double y)
	{
		return x + y - adjustment;
	}
}

namespace No_Adjust
{
	// declarations
	double mul(double x, double y);
	double div(double x, double y);
}

namespace Adjust
{
	constexpr double adjustment{ 0.724 };
	// declarations
	double mul(double x, double y);
	double div(double x, double y);
}

int main()
{
	auto adjust_result = ADJUST::add(2, 3);
	std::cout << "Adjusted result: " << adjust_result << std::endl;

	auto no_adjust_result = NO_ADJUST::add(2, 3);
	std::cout << "No adjusted result: " << no_adjust_result << std::endl;

	std::cout << "\n================================================\n\n";

	double result1 = No_Adjust::div(12, 3);
	std::cout << "result1: " << result1 << std::endl;

	double result2 = Adjust::div(12, 3);
	std::cout << "result2: " << result2 << std::endl;

	return 0;
}

namespace No_Adjust
{
	// definitions
	double mul(double x, double y)
	{
		return x * y;
	}
	double div(double x, double y)
	{
		return x / y;
	}
}

namespace Adjust
{
	// definitions
	double mul(double x, double y)
	{
		return x * y - adjustment;
	}
	double div(double x, double y)
	{
		return x / y - adjustment;
	}
}