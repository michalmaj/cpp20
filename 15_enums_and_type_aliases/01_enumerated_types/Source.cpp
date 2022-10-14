#include <iostream>
#include <typeinfo>

// Declare an enum type
// If we don't give any value, numeration starts from 0. But we can change it.
// In addition default underlying type is int, but we can change it as well (must be integral).
enum class Month : unsigned char // change type to unsigned char (can represent values [0-255]
{
	Jan=1, January=1, Feb, Mar, // In this case January is the same as Jan
	Apr, May, Jun,
	Jul, Aug, Sep, September=Sep, // Better version for making two names to be the same
	Oct=20, Nov, Dec // Because Oct is 20, Dec will be 22
};

int main()
{

	Month month{ Month::Dec };
	//std::cout << "month: " << month << std::endl; // It's impossible to print month directly

	std::cout << "month: " << static_cast<int>(month) << std::endl; // But we can cast to int type
																	// which is default type for enum
	std::cout << "sizeof(month): " << sizeof(month) << ", type : "
		<< typeid(month).name() << std::endl;


	return 0;

}