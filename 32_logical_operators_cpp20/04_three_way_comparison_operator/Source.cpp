#include <iostream>
#include <limits>

int main()
{
	std::string m1{ "Hello" };
	std::string m2{ "World" }; // World comes after Hello in alphabetical order so it's
								   // considered to be greater

	auto result = m1.compare(m2);

	if (result > 0)
		std::cout << "m1 > m2" << std::endl;
	else if(result == 0)
		std::cout << "m1 == m2" << std::endl;
	else if(result < 0)
		std::cout << "m1 < m2" << std::endl;

	std::cout << "\n==================================\n\n";

	// Three way comparison: spaceship operator <=>
	int n1{ 5 };
	int n2{ 5 };

	auto result1{ n1 <=> n2 };

	std::cout << std::boolalpha;
	std::cout << "n1 > n2: " << ((n1 <=> n2) > 0) << std::endl;
	std::cout << "n1 >= n2: " << ((n1 <=> n2) >= 0) << std::endl;
	std::cout << "n1 == n2: " << ((n1 <=> n2) == 0) << std::endl;
	std::cout << "n1 < n2: " << ((n1 <=> n2) < 0) << std::endl;
	std::cout << "n1 <= n2: " << ((n1 <=> n2) <= 0) << std::endl;

	std::cout << "\n==================================\n\n";

	// Strong ordering
	int n4{ 5 };
	int n5{ 5 };

	std::cout << "n4 > n5: " << (n4 > n5) << std::endl; // false
	std::cout << "n4 == n5: " << (n4 == n5) << std::endl; // true: Absolute equality
	std::cout << "n4 < n5: " << (n4 < n5) << std::endl; // false

	std::cout << "\n==================================\n\n";

	// Weak ordering
	std::string m3{ "Hello" };
	std::string m4{ "HELLO" };

	std::cout << "m3 > m4: " << (m3 > m4) << std::endl; // true
	std::cout << "m3 == m4: " << (m3 == m4) << std::endl; // false: equivalence
	std::cout << "m3 < m4: " << (m3 < m4) << std::endl; // false

	std::cout << "\n==================================\n\n";

	// Partial ordering
	double d1{ 12.9 };
	double d2{ std::numeric_limits<double>::quiet_NaN() };

	// d1 is neither >, < or == to d2
	std::cout << "d1 > d2: " << (d1 > d2) << std::endl; // false
	std::cout << "d1 == d2: " << (d1 == d2) << std::endl; // false
	std::cout << "d1 < d2: " << (d1 < d2) << std::endl; // false

	return 0;
}