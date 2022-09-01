/*
 * We can represent numbers with fractional parts.
 * There are three types we can use in C++:
 *	1) float - has size of 4 bytes and precision of 7
 *	2) double - has size of 8 bytes and precision of 15
 *	3) log double - has size of 12 bytes and precision greater than double
 */

#include <iostream>
#include <iomanip> // library to set up precision

int main()
{

    // declare three types of floating point numbers in C+
    float num1{ 1.12345678901234567890f }; // small letter f at the end means float 
    double num2{ 1.12345678901234567890 };
    long double num3{ 1.12345678901234567890L }; // big letter L means long

    // sizeof
    std::cout << "sizeof float: " << sizeof(float) << std::endl;
    std::cout << "sizeof double: " << sizeof(double) << std::endl;
    std::cout << "sizeof long double: " << sizeof(long double) << std::endl;

    // change precision
    std::cout << std::setprecision(20); // change precision for cout
    std::cout << "num1 is: " << num1 << std::endl;
    std::cout << "num2 is: " << num2 << std::endl;
    std::cout << "num3 is: " << num3 << std::endl;

    // some problems with precision, because it usually limited
    float num4{ 192400023.0f };
    std::cout << "num4 is: " << num4 << std::endl; // number lost precision

    double numn4_1{ 192400023.0 };
    std::cout << "num4_1 is: " << numn4_1 << std::endl; // here eventing is OK

    std::cout << std::endl;

    // scientific notation
    // it's handy when we deal with larg or small numbers
    double num5{ 192400023 };
    double num6{ 1.92400023e8 }; // same as above but in scientific notation
    double num7{ 1.924e8 };
    std::cout << "num4 is: " << num5 << std::endl;
    std::cout << "num6 is: " << num6 << std::endl;
    std::cout << "num7 is: " << num7 << std::endl;

    double num8{ 0.00000000003498 };
    double num9{ 3.498e-11 }; // same as above but in scientific notation
    std::cout << "num8 is: " << num8 << std::endl;
    std::cout << "num9 is: " << num9 << std::endl;

    std::cout << std::endl;

    // infinity and NaN (Not a Number)
    // dividing floating point value by 0 generates infinity
    double num10{ 5.6 };
    double num11{}; // initialize to 0
    double num12{}; // initialize to 0

    // infinity
    double res{ num10 / num11 };

    std::cout << num10 << " / " << num11 << " = " << res << std::endl;
    std::cout << res << " + " << num10 << " = " << res + num10 << std::endl;

    // dividing float 0.0 by float 0.0 we get NaN
    res = num11 / num12;
    std::cout << num11 << " / " << num12 << " = " << res << std::endl;

    return 0;
}