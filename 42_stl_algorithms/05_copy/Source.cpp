#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void print_collection(const T& collection)
{
	std::cout << "collection [";
	for (const auto& e : collection)
		std::cout << " " << e;
	std::cout << " ]" << std::endl;
}

int main()
{
	//std::vector<int> source{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int source[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::vector<int> dest{ 15, 21, 12, 53, 30, 40 };

	std::cout << "source: ";
	print_collection(source);

	std::cout << "dest: ";
	print_collection(dest);

	// Copy from source to dest
	// Copy elements from source in the range [std::begin(source), std::begin(source)+4]
	// to dest, starting from iterator std::begin(dest)
	// Make sure you are copying from valid ranges either is dest or source
	std::copy(std::begin(source), std::begin(source) + 4, std::begin(dest));

	std::cout << "source: ";
	print_collection(source);

	std::cout << "dest: ";
	print_collection(dest);

	std::cout << "\n==================================================\n\n";

	std::vector<int> dest1{ 100, 200, 300, 400, 500, 600 };

	std::cout << "source: ";
	print_collection(source);

	std::cout << "dest1: ";
	print_collection(dest1);

	auto odd = [](int n) {return (n % 2) != 0; };

	// If there are more elements in source than the space available in dest,
	// surplus elements will just be ignored
	std::copy_if(std::begin(source), std::end(source), std::begin(dest1), odd);

	std::cout << "source: ";
	print_collection(source);

	std::cout << "dest1: ";
	print_collection(dest1);



	return 0;
}