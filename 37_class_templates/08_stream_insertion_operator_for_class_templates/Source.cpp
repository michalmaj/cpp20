#include "boxcontainer.h"


int main()
{
	BoxContainer<int> int_box;
	int_box.add(1);
	int_box.add(2);

	std::cout << "int_box: " << int_box << std::endl;



	return 0;
}