/*
 * First rule is that: "All variables in an expression should be of the same type".
 * If a compiler notices that we have a different types, it's going to insert an
 * implicit conversion on our types. For example:
 * int + double - double * int
 * all int's will be converted to doubles.
 * Second rule "Smaller types will be converted to bigger type in memory sizes".
 * Implicit conversions are done by the compiler without our involvement.
 */

#include <iostream>


int main()
{

	return 0;
}