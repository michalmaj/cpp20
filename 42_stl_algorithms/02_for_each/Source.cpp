#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

struct Sum
{
	void operator()(int n) { sum += n; }
	int sum{ 0 };
};

int main()
{
	//std::vector<int> nums{ 3, 4, 2, 8, 15, 267 };
	//std::set<int> nums{ 3, 4, 2, 8, 15, 267 };
	int nums[]{ 3, 4, 2, 8, 15, 267 };

	auto print = [](const int& n)
	{
		std::cout << " " << n;
	};

	// Print each element in the collection: lambda function predicate
	std::for_each(std::begin(nums), std::end(nums), print);
	std::cout << std::endl;

	std::cout << "\n==================================================\n\n";

	// Predicate that modifies elements in place
	std::for_each(std::begin(nums), std::end(nums), [](int& n) {n++; });

	// Print
	std::for_each(std::begin(nums), std::end(nums), print);
	std::cout << std::endl;

	std::cout << "\n==================================================\n\n";

	// Capturing result through stateful functor that's returned
	// calls SUm::operator() for each number
	Sum s;
	s = std::for_each(std::begin(nums), std::end(nums), s);
	std::cout << "result: " << s.sum << std::endl;

	std::cout << "\n==================================================\n\n";

	// Using a lambda that captures a local variables by reference and modifies it
	int our_result{ 0 };
	std::for_each(std::begin(nums), std::end(nums), [&our_result](int n) {our_result += n; });
	std::cout << "result: " << our_result << std::endl;



	return 0;
}