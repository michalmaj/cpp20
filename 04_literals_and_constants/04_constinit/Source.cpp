/*
 * constinit is a new C++20 keyword.
 * constinit can only be applied t variables with static or thread storage duration.
 * This, in part means variables outside the scope of the main function.
 * constinit is in place in part to help avoiding problems with the order of initializations
 * of global variables.
 * constinit variables must be initialized with constexpr or literal.
 * constinit and const can be combined.
 * constinit doesn't imply that the variable is constant. It just implies that the
 * compiler enforces initialization at compile time.
 */

#include <iostream>

const int val1{ 33 };
constexpr int val2{ 34 };
int val3{ 35 };

constinit int age{ 88 };
const constinit int age1{ val2 }; // const and constinit can be combined
constinit int age2{ val2 }; // Initializing with age would lead to a compiler error
							// age is not constant

//constinit int age3{ val3 }; // val3 is evaluated at runtime

const constinit double weight{ 33.33 };
//constexpr constinit double scale{ 3.11 }; // Can't combine constinit and constexpr

int main()
{
    //constinit double height{1.72};

    std::cout << "age : " << age << std::endl;
    std::cout << "age1 : " << age1 << std::endl;
    std::cout << "age2 : " << age2 << std::endl;

    age = 33; // Can change a const init variable
    std::cout << "age : " << age << std::endl;

    //Combining const and constinit
    std::cout << "weight : " << weight << std::endl;
    //weight = 44.44; // Compiler error
	return 0;
}