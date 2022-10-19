#include <iostream>

//// In this case we will return a copy
//auto max(int& a, int& b)
//{
//	if (a > b)
//		return a; // return a copy
//	return b; // return a copy
//}

//// We can use two possibilities - first use auto with &
//auto& max(int& a, int& b)
//{
//	if (a > b)
//		return a; // return a copy
//	return b; // return a copy
//}

// and second use decltype(auto)
decltype(auto) max(int& a, int& b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	int x{ 10 };
	int y{ 45 };

	int& result = max(x, y); // Error : Can not treat return value as a reference
									   // It's jut a bare separate variable with a value inside.

	//int result = max(x,y); // A copy of the max is returned

	++result;

	std::cout << "x: " << x << std::endl; // 10
	std::cout << "y: " << y << std::endl; // 46
	std::cout << "result: " << result << std::endl; // 46

	return 0;
}