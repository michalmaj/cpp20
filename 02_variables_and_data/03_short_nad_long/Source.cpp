/*
 * We can have signed or unsigned integers.
 * Their range for 4 bytes is:
 * for unsigned: [0 ~ 2^n - 1], in values is 0 to 4,294,967,295
 * for signed: [-2^(n-1) ~ 2^(n-1) - 1], in values is -2,147,483,648 to 2,147,483,647
 *
 * We can also flag our integers as: short or long.
 * These modifiers only apply to integral types, those in which
 * we can store decimal numbers.
 */

#include <iostream>

int main()
{
	int value1{ 10 };
	int value2{ -300 };

	std::cout << "value1: " << value1 << std::endl;
	std::cout << "value2: " << value2 << std::endl;

	// It doesn't matter if number is negative or positive
	// both have sizeof 4 bytes
	std::cout << "sizeof(value1): " << sizeof(value1) << std::endl;
	std::cout << "sizeof(value2): " << sizeof(value2) << std::endl;

	// we can store only unsigned value
	unsigned int value3{ 4 };

	// if we try to put a negative value to unsigned we will have a compiler error
	//unsigned int value4{ -5 };

	// short and long
    short short_var{ -32768 }; //  2 Bytes 
    short int short_int{ 455 }; // 
    signed short signed_short{ 122 }; //
    signed short int signed_short_int{ -456 }; // 
    unsigned short int unsigned_short_int{ 456 };
    std::cout << "Short variable : " << short_var << " , size : "
        << sizeof(short) << " bytes" << std::endl;

    std::cout << "Short Int : " << short_int << " , size : "
        << sizeof(short int) << " bytes" << std::endl;

    std::cout << "Signed short : " << signed_short
        << " , size : " << sizeof(signed short) << " bytes" << std::endl;

    std::cout << "Signed short int :  " << signed_short_int
        << " , size : " << sizeof(signed short int) << " bytes" << std::endl;

    std::cout << "unsigned short int :  " << unsigned_short_int
        << " , size : " << sizeof(unsigned short int) << " bytes" << std::endl;

    std::cout << "---------------------" << std::endl;

    int int_var{ 55 }; // 4 bytes
    signed signed_var{ 66 };//
    signed int signed_int{ 77 };//
    unsigned int unsigned_int{ 77 };
    std::cout << "Int variable :  " << int_var << " , size : "
        << sizeof(int) << " bytes" << std::endl;

    std::cout << "Signed variable " << signed_var << " , size : "
        << sizeof(signed) << " bytes" << std::endl;

    std::cout << "Signed int :  " << signed_int << " , size : "
        << sizeof(signed int) << " bytes" << std::endl;

    std::cout << "unsigned int :  " << unsigned_int << " , size : "
        << sizeof(unsigned int) << " bytes" << std::endl;

    std::cout << "---------------------" << std::endl;

    long long_var{ 88 }; // 4 OR 8 Bytes
    long int long_int{ 33 };
    signed long signed_long{ 44 };
    signed long int signed_long_int{ 44 };
    unsigned long int unsigned_long_int{ 44 };
    std::cout << "Long variable :  " << long_var << " , size : "
        << sizeof(long) << " bytes" << std::endl;

    std::cout << "Long int :  " << long_int << " , size : "
        << sizeof(long int) << " bytes" << std::endl;

    std::cout << "Signed long :  " << signed_long << " , size : "
        << sizeof(signed long) << " bytes" << std::endl;

    std::cout << "Signed long int : " << signed_long_int << " , size : "
        << sizeof(signed long int) << " bytes" << std::endl;

    std::cout << "unsigned long int : " << unsigned_long_int << " , size : "
        << sizeof(unsigned long int) << " bytes" << std::endl;

    std::cout << "---------------------" << std::endl;

    long long long_long{ 888 };// 8 Bytes
    long long int long_long_int{ 999 };
    signed long long signed_long_long{ 444 };
    signed long long int signed_long_long_int{ 1234 };
    unsigned long long int unsigned_long_long_int{ 1234 };

    std::cout << "Long long : " << long_long << " , size : "
        << sizeof(long long) << " bytes" << std::endl;

    std::cout << "Long long int : " << long_long_int << " , size : "
        << sizeof(long long int) << " bytes" << std::endl;

    std::cout << "Signed long long : " << signed_long_long << " , size : "
        << sizeof(signed long long) << " bytes" << std::endl;

    std::cout << "Signed long long int : " << signed_long_long_int << " , size : "
        << sizeof(signed long long int) << " bytes" << std::endl;

    std::cout << "unsigned long long int : " << unsigned_long_long_int << " , size : "
        << sizeof(unsigned long long int) << " bytes" << std::endl; 


	return 0;
}