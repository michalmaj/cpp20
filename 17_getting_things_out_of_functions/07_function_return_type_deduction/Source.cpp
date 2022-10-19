#include <iostream>
#include <typeinfo>

//// Good version - both return statements have ints 
//auto process_number(int value)
//{
//	if (value < 10)
//		return 22; // returning int literal
//	return 55; // returning int literal
//}

//// Bad version - both return statements have different types
//auto process_number(int value)
//{
//	if (value < 10)
//		return 22; // returning int literal
//	return 33.1; // returning double literal
//}

//// first solution for above problem - use int (33.1 will but reduce to just 33)
//// or double instead of auto
//int process_number(int value)
//{
//	if (value < 10)
//		return 22; // returning int literal
//	return 33.1; // returning double literal
//}

// second solution is cast explicitly to double
auto process_number(int value)
{
	if (value < 10)
		return static_cast<double>(22); // returning int literal
	return 33.1; // returning double literal
}

int main()
{

	auto result = process_number(7);
	std::cout << "result: " << result << std::endl;
	std::cout << "sizeof(result): " << sizeof(result) << ", type: " << typeid(result).name() << std::endl;



	return 0;
}