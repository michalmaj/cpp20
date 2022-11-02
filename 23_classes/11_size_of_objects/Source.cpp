#include <iostream>

class Dog {
public:
    Dog() = default;
    void prin_info() {

    }
    void do_something() {

    }

private:
    size_t leg_count; //8
    size_t arm_count; //8
    int* p_age; // 8
};


int main() {

    Dog dog1;
    std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl; // 8
    std::cout << "sizeof(int*) : " << sizeof(int*) << std::endl; // 8
    std::cout << "sizeof(Dog) : " << sizeof(dog1) << std::endl; // 24

    std::string name{ "I am the king of the universe!" };

    std::cout << "sizeof(name) : " << sizeof(name) << std::endl; // 40

    return 0;
}