#include <iostream>

// Both below functions are OK, const int* is something else than int*
int max(int* a, int* b) {
    std::cout << "max with int* called" << std::endl;
    return (*a > *b) ? *a : *b;
}

int max(const int* a, const int* b) {
    std::cout << "max with const int* called" << std::endl;
    return (*a > *b) ? *a : *b;
}

// But this function is (in the eyes of compiler) a equivalent af function above - it's Redefinition
/*
int min(const int* a, const int* b){
    return (*a < *b)? *a : *b;
}
*/


int min(const int* const a, const int* const b) {
    std::cout << "&a : " << &a << std::endl;
    std::cout << "&b : " << &b << std::endl;
    return (*a < *b) ? *a : *b;
}

int main()
{


    int a{10};
    int b{12};
    const int c{30};
    const int d{15};
    auto result = max(&c,&d);
    std::cout << "result: " << result << std::endl;

    std::cout << "\n=====================================\n\n";

    const int* p_c{ &c };
    const int* p_d{ &d };

    std::cout << "&p_c : " << &p_c << std::endl;
    std::cout << "&p_d : " << &p_d << std::endl;

    auto result1 = min(p_c, p_d);
    std::cout << "result1: " << result1 << std::endl;


    return 0;
}