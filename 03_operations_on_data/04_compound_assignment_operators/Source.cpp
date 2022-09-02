/*
 * The compound assignment operators consist of a binary operator and the simple
 * assignment operator. They perform the operation of the binary operator on both
 * operands and store the result of that operation into the left operand,
 * which must be a modifiable lvalue.
 * In other words it is a equivalent of for example:
 *      a = a + b
 *  using compound assignment it looks like this:
 *      a += b
 */

#include <iostream>


int main()
{
    int value{ 45 };

    std::cout << "The value is : " << value << std::endl;

    std::cout << std::endl;
    value = value + 5;
    //value +=5; // equivalent to value = value + 5
    std::cout << "The value is (after +=5) : " << value << std::endl; // 50

    std::cout << std::endl;
    value -= 5; // equivalent to value = value - 5
    std::cout << "The value is (after -=5) : " << value << std::endl; // 45 

    std::cout << std::endl;
    value *= 2;
    std::cout << "The value is (after *=2) : " << value << std::endl; // 90

    std::cout << std::endl;
    value /= 3;
    std::cout << "The value is (after /=3) : " << value << std::endl; // 30

    std::cout << std::endl;
    value %= 11;
    std::cout << "The value is (after %=11) : " << value << std::endl;// 8

	return 0;
}