#include <iostream>
#include <array>


//double sum( double scores[], size_t count){
double sum(double* scores, size_t count) {

    double score_sum{};

    // in function we have only the size of the pointer (8 bytes)
	std::cout << "sizeof(scores)  : " << sizeof(scores) << std::endl; // 8 bytes
	std::cout << "sizeof(int*) : " << sizeof (int *) << std::endl; // 8 bytes
    //size_t arr_size = std::size(scores);

    for (size_t i{ 0 }; i < count; ++i) {
        score_sum += scores[i];
    }
    return score_sum;
}



int main() {
    double my_scores[]{ 10.5,34.3,4.8,6.5 };
    std::cout << "sizeof(my_scores) : " << sizeof(my_scores) << std::endl; // 4 values * 8 bytes = 32


    double result = sum(my_scores, std::size(my_scores));
    std::cout << "result : " << result << std::endl;

    return 0;
}