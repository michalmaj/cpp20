#include <iostream>

void say_age(const int& age); // Declaration

int main() {

    int age{ 23 }; // Local
    std::cout << "age (before call) : " << age << "&age : " << &age << std::endl; // 23
    say_age(age); // During passing by pointer we have to pass an address (&) 
    std::cout << "age (after call) : " << age << "&age : " << &age << std::endl; // 23

    return 0;
}


void say_age(const int& age) { // Parameter
    //++age; // Can't modify const
    std::cout << "Hello , you are " << age << " years old! &age : " << &age << std::endl; // 23
}