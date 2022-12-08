#include "parent.h"
#include "child.h"


int main()
{
	Parent parent1;
	parent1.print_var();

	std::cout << "\n=================================\n\n";

	Child child1{ 33 };
	child1.print_var(); // Calls the method in Child
	child1.Parent::print_var(); // Calls the method in Parent,
								// value in parent just contains junk or whatever
								// in class initialization we did.

	std::cout << "\n=================================\n\n";

	child1.show_values();

	return 0;
}