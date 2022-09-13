#include <iostream>
#include <iomanip>


int main()
{
	// For loop
	std::cout << "Tabular data visualization with nested for loops:" << std::endl;

	// Set number of rows and columns
	const size_t ROWS{ 12 };
	const size_t COLS{ 3 };

	for(size_t row{0}; row < ROWS; ++row)
	{
		for(size_t col{0}; col < COLS; ++col)
		{
			std::cout << "(row " << std::setw(2) << row << ", col " << std::setw(2)
				<< col << ")\t";
		}
		std::cout << std::endl;
	}

	std::cout << "\n==================================\n" << std::endl;

	// While loop
	std::cout << "Tabular data visualization with nested while loops:" << std::endl;

	size_t row{ 0 };
	size_t col{ 0 };

	while(row < ROWS)
	{
		while(col < COLS)
		{
			std::cout << "(row " << std::setw(2) << row << ", col " << std::setw(2)
				<< col << ")\t";
			++col;
		}
		std::cout << std::endl;

		col = 0; // Reset col to 0 to allow start next column iteration for next row
				 // from 0.
		++row;
	}


	std::cout << "\n==================================\n" << std::endl;

	// Do-while loop
	std::cout << "Tabular data visualization with nested do-while loops:" << std::endl;

	row = 0;
	col = 0;

	do
	{
		do
		{
			std::cout << "(row " << std::setw(2) << row << ", col " << std::setw(2)
				<< col << ")\t";
			++col;
		} while (col < COLS);
		std::cout << std::endl;

		col = 0; // Reset col to 0 to allow start next column iteration for next row
		// from 0.
		++row;
	} while (row < ROWS);


	return 0;
}