#include <iostream>
#include <vector>


int main()
{
	std::vector<int> numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// Trying out revers iterators
	auto it = numbers.rbegin(); // A reverse iterator increments backwards from
								// the end to the begin
	// Another version
	//std::vector<int>::reverse_iterator it = numbers.rbegin();

	std::cout << "Numbers: [";
	while(it != numbers.rend())
	{
		std::cout << " " << *it;
		++it;
	}
	std::cout << " ]" << std::endl;

	std::cout << "\n==================================================\n\n";

	auto it_rev = numbers.rbegin();
	//if(it_rev != numbers.end()) // Compiler Error
	//{
	//	std::cout << "Do something..." << std::endl;
	//}

	return 0;
}