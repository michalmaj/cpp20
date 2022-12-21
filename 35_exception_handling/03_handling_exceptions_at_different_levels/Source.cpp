#include <iostream>

void f1();
void f2();
void f3();

//void exception_thrower()
//{
//	std::cout << "starting execution_thrower()" << std::endl;
//	throw 0; // Execution will halt from here
//	std::cout << "ending execution_thrower()" << std::endl;
//}

// Another way is to handle exception directly in exception_thrower
void exception_thrower()
{
	std::cout << "starting execution_thrower()" << std::endl;
	try
	{
		throw 0; // Execution will halt from here
	}catch (int& ex)
	{
		std::cout << "Something went wrong" << std::endl;
	}
	std::cout << "ending execution_thrower()" << std::endl;
}

int main()
{
	// for exception handling in functions
	f1();

	// For exception handling in main
	//try
	//{
	//	f1();
	//}catch(int& ex)
	//{
	//	std::cout << "Handling execution in main()" << std::endl;
	//}

	std::cout << "END" << std::endl;
	return 0;
}

// Uncomment one of the following examples (1-6):

//// 1. Regular flow - no kind of exception is thrown
//void f1()
//{
//	std::cout << "Starting f1()" << std::endl;
//	f2();
//	std::cout << "Ending f1()" << std::endl;
//}
//void f2()
//{
//	std::cout << "Starting f2()" << std::endl;
//	f3();
//	std::cout << "Ending f2()" << std::endl;
//}
//void f3()
//{
//	std::cout << "Starting f3()" << std::endl;
//	std::cout << "Ending f3()" << std::endl;
//}

//// 2. Exception thrown from f3() scope: not handled anywhere
//void f1()
//{
//	std::cout << "Starting f1()" << std::endl;
//	f2();
//	std::cout << "Ending f1()" << std::endl;
//}
//void f2()
//{
//	std::cout << "Starting f2()" << std::endl;
//	f3();
//	std::cout << "Ending f2()" << std::endl;
//}
//void f3()
//{
//	std::cout << "Starting f3()" << std::endl;
//	exception_thrower();
//	std::cout << "Ending f3()" << std::endl;
//}

//// 3. Exception thrown from f3() scope: handled in f3()
//void f1()
//{
//	std::cout << "Starting f1()" << std::endl;
//	f2();
//	std::cout << "Ending f1()" << std::endl;
//}
//void f2()
//{
//	std::cout << "Starting f2()" << std::endl;
//	f3();
//	std::cout << "Ending f2()" << std::endl;
//}
//void f3()
//{
//	std::cout << "Starting f3()" << std::endl;
//	try 
//	{
//		exception_thrower();
//	}catch (int& ex)
//	{
//		std::cout << "Handling execution in f3()" << std::endl;
//	}
//	std::cout << "Ending f3()" << std::endl;
//}

//// 4. Exception thrown from f3() scope: handled in f2()
//void f1()
//{
//	std::cout << "Starting f1()" << std::endl;
//	f2();
//	std::cout << "Ending f1()" << std::endl;
//}
//void f2()
//{
//	std::cout << "Starting f2()" << std::endl;
//	try
//	{
//		f3();
//	}catch (int& ex)
//	{
//		std::cout << "Handling execution in f2()" << std::endl;
//	}
//	std::cout << "Ending f2()" << std::endl;
//}
//void f3()
//{
//	std::cout << "Starting f3()" << std::endl;
//	exception_thrower();
//	std::cout << "Ending f3()" << std::endl;
//}

//// 5. Exception thrown from f3() scope: handled in f1()
//void f1()
//{
//	std::cout << "Starting f1()" << std::endl;
//	try
//	{
//		f2();
//	}
//	catch (int& ex)
//	{
//		std::cout << "Handling execution in f1()" << std::endl;
//	}
//	std::cout << "Ending f1()" << std::endl;
//}
//void f2()
//{
//	std::cout << "Starting f2()" << std::endl;
//	f3();
//	std::cout << "Ending f2()" << std::endl;
//}
//void f3()
//{
//	std::cout << "Starting f3()" << std::endl;
//	exception_thrower();
//	std::cout << "Ending f3()" << std::endl;
//}

// 6. Exception thrown from f3() scope: handled in main()
void f1()
{
	std::cout << "Starting f1()" << std::endl;
	f2();
	std::cout << "Ending f1()" << std::endl;
}
void f2()
{
	std::cout << "Starting f2()" << std::endl;
	f3();
	std::cout << "Ending f2()" << std::endl;
}
void f3()
{
	std::cout << "Starting f3()" << std::endl;
	exception_thrower();
	std::cout << "Ending f3()" << std::endl;
}