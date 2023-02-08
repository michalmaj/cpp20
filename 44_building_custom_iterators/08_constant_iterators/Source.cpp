#include "boxcontainer.h"

template <typename T>
void print(const BoxContainer<T>& c)
{
	for (const auto& e : c)
		std::cout << e << " ";
	std::cout << std::endl;
}

int main()
{
	BoxContainer<int> vi{ 5, 1, 7, 2, 5, 3, 7, 9, 6 };

	const BoxContainer<int> copy(vi);

	std::cout << "data:" << std::endl;
	for(auto it = copy.begin(); it != copy.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << std::endl;

	print(copy);

	return 0;
}