#include <iostream>

void print_sum(const int* param1, const int* param2) {
    std::cout << "sum : " << (*param1 + *param2) << std::endl;
}

int main() {

    int a{ 3 };
    int b{ 12 };

    print_sum(&a, &b);

    double c{ 4.5 };
    double d{ 3.7 };
    //print_sum(&c, &d); // Compiler Error even parameters marked as const

    return 0;
}