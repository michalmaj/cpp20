#include <iostream>

void say_age(const int age); // Declaration

int main() {

    int age{ 23 }; // Local
    std::cout << "age (before call) : " << age << "&age : " << &age << std::endl;
    say_age(age); // Argument
    std::cout << "age (after call) : " << age << "&age : " << &age << std::endl;

    return 0;
}


void say_age(const int age) { // Parameter
    ///++age; // can't change value of const value 
    std::cout << "Hello , you are " << age << " years old! &age : " << &age << std::endl;
}