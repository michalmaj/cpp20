#include <iostream>

namespace Level1
{
	namespace Level2
	{
		namespace Level3
		{
			const double weight{ 33.33 };
		}
	}
}

int main()
{
	std::cout << "Weight: " << Level1::Level2::Level3::weight << std::endl;

	namespace Data = Level1::Level2::Level3;

	std::cout << "Weight: " << Data::weight << std::endl;

	return 0;
}