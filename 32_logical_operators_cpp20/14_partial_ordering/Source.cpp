#include "point.h"


int main()
{
    Point p1(110, 110);
    Point p2(20, 20);

    std::cout << std::boolalpha;
    auto result1 = (p1 > p2);
    std::cout << "p1 > p2 : " << result1 << std::endl;

    auto result2 = (p1 >= p2);
    std::cout << "p1 >= p2 : " << result2 << std::endl;

    auto result3 = (p1 == p2);
    std::cout << "p1 == p2 : " << result3 << std::endl;

    auto result4 = (p1 != p2);
    std::cout << "p1 != p2 : " << result4 << std::endl;

    auto result5 = (p1 < p2);
    std::cout << "p1 < p2 : " << result5 << std::endl;

    auto result6 = (p1 <= p2);
    std::cout << "p1 <= p2 : " << result6 << std::endl;

	return 0;
}