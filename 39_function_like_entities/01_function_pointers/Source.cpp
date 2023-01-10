#include <iostream>

double add(double a, double b)
{
	return a + b;
}

int main()
{
	// All syntax below is correct
	/*double (*f_ptr) (double, double) = &add;*/
	/*double (*f_ptr) (double, double) = add;*/
	/*double (*f_ptr) (double, double) {add};*/
	/*double (*f_ptr) (double, double) { &add };*/
	/*auto f_ptr = add;*/
	/*auto f_ptr = &add;*/
	/*auto f_ptr{ add };*/
	/*auto f_ptr{ &add };*/
	/*auto* f_ptr = add;*/
	auto* f_ptr = &add;	

	std::cout << "add(10, 30): " << f_ptr(10, 30) << std::endl;

	// We can also initialize a function pointer with nullptr
	double (*f_ptr_null) (double, double) = nullptr;

	// Now we can't call our function pointer, because it is a nullptr
	std::cout << "add(10, 30): " << f_ptr_null(10, 30) << std::endl; // Program is going to crash

	// But things may go wrong
	//int(*f_ptr_bad)(double, double) = add; // Compiler Error


	return 0;
}