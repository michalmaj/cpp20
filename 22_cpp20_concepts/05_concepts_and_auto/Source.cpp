#include <iostream>
#include <concepts>

// This syntax contains the auto parameters you pass in
// to comply with the std::integral concept
std::integral auto add(std::integral auto a, std::integral auto b)
{
	return a + b;
}

int main()
{

	//add(10.9, 0.1); // Compiler error, we have here double literals, so our constrain (std::integral) is violate.

	std::integral auto x = add(10, 8);

	std::floating_point auto y = 3.9;

	return 0;
}