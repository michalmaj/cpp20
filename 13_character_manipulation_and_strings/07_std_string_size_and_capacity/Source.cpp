#include <iostream>
#include <string>

int main()
{
    std::string str1{ "Hello World" };
    std::string str2;
    std::string str3{};

    // Empty
    std::cout << std::endl;
    std::cout << "std::string::empty() : " << std::endl;
    std::cout << "str1 is empty : " << std::boolalpha << str1.empty() << std::endl; // true
    std::cout << "str2 is empty : " << std::boolalpha << str2.empty() << std::endl; // false
    std::cout << "str3 is empty : " << std::boolalpha << str3.empty() << std::endl; // false
    // Size
    std::cout << std::endl;
    std::cout << "std::string::size() : " << std::endl;
    std::cout << "str1 contains " << str1.size() << " characters" << std::endl; // 11
    std::cout << "str2 contains " << str2.size() << " characters" << std::endl; // 0
    std::cout << "str3 contains " << str3.size() << " characters" << std::endl; // 0
    // Length
    std::cout << std::endl;
    std::cout << "std::string::length() : " << std::endl;
    std::cout << "str1 contains " << str1.length() << " characters" << std::endl; // 11
    std::cout << "str2 contains " << str2.length() << " characters" << std::endl; // 0
    std::cout << "str3 contains " << str3.length() << " characters" << std::endl; // 0

    std::cout << "\n============================================================\n\n";

    // max_size: max number of characters a string can have on the system
    std::string str4{ "Hello World" };
    std::cout << "std::string can hold: " << str1.max_size() << " characters" << std::endl;

    std::cout << "\n============================================================\n\n";

    //Capacity
    std::string str5 {"Hello World"};
    std::string str6;
    std::cout << "str5 capacity : " << str5.capacity() << std::endl;
    std::cout << "str6 capacity : " << str6.capacity() << std::endl;

    str1 = "The sky is so blue, the grass is green. Kids are running all over the place";

    std::cout << "str5 size : " << str5.size() << std::endl;
    std::cout << "str6 capacity : " << str6.size() << std::endl;

    std::cout << "\n============================================================\n\n";

    //Reserve : Update the capacity
    std::string str7{ "Hello World" };
    std::cout << "str7 capacity : " << str7.capacity() << std::endl; // 15
    std::cout << "str7 size : " << str7.size() << std::endl;
    str1.reserve(100);

    std::cout << "str7 after reserve : " << str7 << std::endl;
    std::cout << "str7 capacity : " << str7.capacity() << std::endl; // 100
    std::cout << "str7 size : " << str7.size() << std::endl;

    std::cout << "\n============================================================\n\n";

    // shrink_to_fit
    std::string str8{ "Hello World" };
    str8.reserve(100);
    std::cout << "str8 capacity : " << str8.capacity() << std::endl;
    std::cout << "str8 size : " << str8.size() << std::endl;

    str8.shrink_to_fit();

    std::cout << "str8 capacity : " << str8.capacity() << std::endl;
    std::cout << "str8 size : " << str8.size() << std::endl;



	return 0;
}