#include <iostream>

int dog_count{ 2 }; // global var

void say_age(const int* const p_age); // Declaration

int main() {

    int age{ 23 }; // Local
    std::cout << "age (before call) : " << age << "&age : " << &age << std::endl; // 23
    say_age(&age); // During passing by pointer we have to pass an address (&) 
    std::cout << "age (after call) : " << age << "&age : " << &age << std::endl; // 24

    return 0;
}


void say_age(const int* const p_age) { // Parameter
    //++(*age); // We can't modify the value of pointer to const
    std::cout << "Hello , you are " << *p_age << " years old! &age : " << p_age << std::endl; // 23

    //p_age = &dog_count; // CE: const pointer can't point somewhere else
}