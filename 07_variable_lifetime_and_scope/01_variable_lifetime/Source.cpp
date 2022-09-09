/*
 * Storage duration:
 *	- local
 *	- static
 *	- dynamic
 */

#include <iostream>


int static_var2{ 80 }; // static duration - dies when program ends

void some_function()
{
	int local_var3{ 30 }; // local duration - dies at end of block
	static int static_var1{ 40 }; // static duration - dies when program ends
}

int main()
{
	int local_var1{ 60 }; // local duration - dies at end of block
	{
		int local_var3{ 20 }; // local duration - dies at end of block
	}

	return 0;
}