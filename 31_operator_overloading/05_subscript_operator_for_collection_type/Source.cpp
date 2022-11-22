#include "scores.h"


int main()
{
	Scores scores_math("Maths");
	scores_math.print_info();

	scores_math[15] = 66.4;

	scores_math.print_info();

	// Const object
	const Scores geo("Geography");
	std::cout << "geo[5]: " << geo[5] << std::endl;

	return 0;
}