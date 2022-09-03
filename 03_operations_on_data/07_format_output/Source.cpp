/*
 * Documentation for input/output manipulations:
 * https://en.cppreference.com/w/cpp/io/manip
 */

#include <iostream>
#include <ios>
#include <iomanip>


int main()
{
	// std::endl places a new line character on the output stream.
	// This is identical to placing '\n' on the output stream

	// This data will show up in one line
	std::cout << "Hello";
	std::cout << "World";

	std::cout << std::endl;

	std::cout << "-------------------" << std::endl;

	// This data will show up line by line
	std::cout << "Hello" << std::endl;
	std::cout << "World" << std::endl;

	std::cout << std::endl;

	// \n is almost the same as std::endl
	std::cout << "Hello\n";
	std::cout << "World\n";

	//==============================================================================
	std::cout << std::endl;

	// std::flush flushes the output buffer to its final destination
	std::cout << "This is a nice message..." << std::endl << std::flush;
	// After this std::flush, we're sure that at this line, the message has been sent
	// to the stream. This may be important in some application

	//==============================================================================
	std::cout << std::endl;

	// std::setw() adjusts the filed with for the next item about to be printed
	// std::setw() manipulator only affects the next value to be printed
	// std::setw() requires iomanip header
	std::cout << "Unformatted table: " << std::endl;
	std::cout << "John" << " " << "Snow" << " 30" << std::endl;
	std::cout << "Brynden" << " " << "Tully" << " 63" << std::endl;
	std::cout << "Syrio" << " " << "Forel" << " 45" << std::endl;
	std::cout << "Jaime" << " " << "Lannister" << " 42" << std::endl;
	std::cout << "Barristan" << " " << "Selmy" << " 67" << std::endl;
	std::cout << "Arthur" << " " << "Dayne" << " 39" << std::endl;

	std::cout << std::endl;
	std::cout << "Formatted table: " << std::endl;

	std::cout << "Unformatted table: " << std::endl;
	std::cout << std::setw(10) << "John" << " " << std::setw(10) << "Snow" << std::setw(10) << " 30" << std::endl;
	std::cout << std::setw(10) << "Brynden" << " " << std::setw(10) << "Tully" << std::setw(10) << " 63" << std::endl;
	std::cout << std::setw(10) << "Syrio" << " " << std::setw(10) << "Forel" << std::setw(10) << " 45" << std::endl;
	std::cout << std::setw(10) << "Jaime" << " " << std::setw(10) << "Lannister" << std::setw(10) << " 42" << std::endl;
	std::cout << std::setw(10) << "Barristan" << " " << std::setw(10) << "Selmy" << std::setw(10) << " 67" << std::endl;
	std::cout << std::setw(10) << "Arthur" << " " << std::setw(10) << "Dayne" << std::setw(10) << " 39" << std::endl;

	// Same what above but this time set a variable for column width
	// using magic numbers is a bad idea.
	int col_width{ 14 };
	std::cout << std::endl;
	std::cout << "Formatted table: " << std::endl;

	std::cout << "Unformatted table: " << std::endl;
	std::cout << std::setw(col_width) << "John" << " " << std::setw(col_width) << "Snow" << std::setw(col_width) << " 30" << std::endl;
	std::cout << std::setw(col_width) << "Brynden" << " " << std::setw(col_width) << "Tully" << std::setw(col_width) << " 63" << std::endl;
	std::cout << std::setw(col_width) << "Syrio" << " " << std::setw(col_width) << "Forel" << std::setw(col_width) << " 45" << std::endl;
	std::cout << std::setw(col_width) << "Jaime" << " " << std::setw(col_width) << "Lannister" << std::setw(col_width) << " 42" << std::endl;
	std::cout << std::setw(col_width) << "Barristan" << " " << std::setw(col_width) << "Selmy" << std::setw(col_width) << " 67" << std::endl;
	std::cout << std::setw(col_width) << "Arthur" << " " << std::setw(col_width) << "Dayne" << std::setw(col_width) << " 39" << std::endl;

	// Justify, values can be justified in their fields. There are three manipulators
	// for adjusting the justificationL left, right, and internal
	std::cout << std::endl;
	std::cout << "Right justified table(default): " << std::endl;

	col_width = 20;
	std::cout << std::right;
	std::cout << std::setw(col_width) << "John" << " " << std::setw(col_width) << "Snow" << std::setw(col_width) << " 30" << std::endl;
	std::cout << std::setw(col_width) << "Brynden" << " " << std::setw(col_width) << "Tully" << std::setw(col_width) << " 63" << std::endl;
	std::cout << std::setw(col_width) << "Syrio" << " " << std::setw(col_width) << "Forel" << std::setw(col_width) << " 45" << std::endl;
	std::cout << std::setw(col_width) << "Jaime" << " " << std::setw(col_width) << "Lannister" << std::setw(col_width) << " 42" << std::endl;
	std::cout << std::setw(col_width) << "Barristan" << " " << std::setw(col_width) << "Selmy" << std::setw(col_width) << " 67" << std::endl;
	std::cout << std::setw(col_width) << "Arthur" << " " << std::setw(col_width) << "Dayne" << std::setw(col_width) << " 39" << std::endl;

	std::cout << std::endl;
	std::cout << "Left justified table: " << std::endl;

	col_width = 20;
	std::cout << std::left;
	std::cout << std::setw(col_width) << "John" << " " << std::setw(col_width) << "Snow" << std::setw(col_width) << " 30" << std::endl;
	std::cout << std::setw(col_width) << "Brynden" << " " << std::setw(col_width) << "Tully" << std::setw(col_width) << " 63" << std::endl;
	std::cout << std::setw(col_width) << "Syrio" << " " << std::setw(col_width) << "Forel" << std::setw(col_width) << " 45" << std::endl;
	std::cout << std::setw(col_width) << "Jaime" << " " << std::setw(col_width) << "Lannister" << std::setw(col_width) << " 42" << std::endl;
	std::cout << std::setw(col_width) << "Barristan" << " " << std::setw(col_width) << "Selmy" << std::setw(col_width) << " 67" << std::endl;
	std::cout << std::setw(col_width) << "Arthur" << " " << std::setw(col_width) << "Dayne" << std::setw(col_width) << " 39" << std::endl;

	std::cout << std::endl;
	std::cout << "Internal justified: " << std::endl;

	col_width = 20;
	std::cout << std::right;
	std::cout << std::setw(10) << -123.45 << std::endl;
	std::cout << std::internal;
	std::cout << std::setw(10) << -123.45 << std::endl;

	std::cout << std::endl;
	std::cout << "Table with fill characters: " << std::endl;

	col_width = 20;
	std::cout << std::left;
	std::cout << std::setfill('-'); // the fill character
	std::cout << std::setw(col_width) << "John" << " " << std::setw(col_width) << "Snow" << std::setw(col_width) << " 30" << std::endl;
	std::cout << std::setw(col_width) << "Brynden" << " " << std::setw(col_width) << "Tully" << std::setw(col_width) << " 63" << std::endl;
	std::cout << std::setw(col_width) << "Syrio" << " " << std::setw(col_width) << "Forel" << std::setw(col_width) << " 45" << std::endl;
	std::cout << std::setw(col_width) << "Jaime" << " " << std::setw(col_width) << "Lannister" << std::setw(col_width) << " 42" << std::endl;
	std::cout << std::setw(col_width) << "Barristan" << " " << std::setw(col_width) << "Selmy" << std::setw(col_width) << " 67" << std::endl;
	std::cout << std::setw(col_width) << "Arthur" << " " << std::setw(col_width) << "Dayne" << std::setw(col_width) << " 39" << std::endl;


	//==============================================================================
	std::cout << std::endl;
    //boolalpha and noboolapha : control bool output format : 1/0 or true/false

    bool condition{ true };
    bool other_condition{ false };

    std::cout << "condition: " << condition << std::endl;
    std::cout << "other_condition: " << other_condition << std::endl;

    std::cout << std::endl;
    std::cout << std::boolalpha;
    std::cout << "condition: " << condition << std::endl;
    std::cout << "other_condition: " << other_condition << std::endl;

    std::cout << std::endl;
    std::cout << std::noboolalpha;
    std::cout << "condition: " << condition << std::endl;
    std::cout << "other_condition: " << other_condition << std::endl;

    //===================================================================
    std::cout << std::endl;

    //showpos and noshowpos : show or hide the +  sign for positive numbers

    int pos_num{ 34 };
    int neg_num{ -45 };

    std::cout << "pos_num: " << pos_num << std::endl;
    std::cout << "neg_num: " << neg_num << std::endl;

    std::cout << std::endl;
    std::cout << std::showpos;
    std::cout << "pos_num: " << pos_num << std::endl;
    std::cout << "neg_num: " << neg_num << std::endl;

    std::cout << std::endl;
    std::cout << std::noshowpos;
    std::cout << "pos_num: " << pos_num << std::endl;
    std::cout << "neg_num: " << neg_num << std::endl;


    //===================================================================
    std::cout << std::endl;


    //different number systems : std::dec, std::hex, std::oct
    //it only works with integral types

    int pos_int{ 717171 };
    int neg_int{ -47347 };
    double double_var{ 498.32 };

    std::cout << std::endl;
    std::cout << "default base format: " << std::endl;
    std::cout << "pos_int: " << pos_int << std::endl;
    std::cout << "neg_int: " << neg_int << std::endl;
    std::cout << "double_var: " << double_var << std::endl;

    std::cout << std::endl;
    std::cout << "pos_int in different bases: " << std::endl;
    std::cout << "pos_int (dec): " << std::dec << pos_int << std::endl;
    std::cout << "pos_int (hex): " << std::hex << pos_int << std::endl;
    std::cout << "pos_int (oct): " << std::oct << pos_int << std::endl;

    std::cout << std::endl;
    std::cout << "neg_int in different bases: " << std::endl;
    std::cout << "neg_int (dec): " << std::dec << neg_int << std::endl;
    std::cout << "neg_int (hex): " << std::hex << neg_int << std::endl;
    std::cout << "neg_int (oct): " << std::oct << neg_int << std::endl;

    std::cout << std::endl;
    std::cout << "double_var in different bases: " << std::endl;
    std::cout << "double_var (dec): " << std::dec << double_var << std::endl;
    std::cout << "double_var (hex): " << std::hex << double_var << std::endl;
    std::cout << "double_var (oct): " << std::oct << double_var << std::endl;


    //===================================================================
    std::cout << std::endl;


    //uppercase and nouppercase

    pos_int = 717171;

    std::cout << "pos_int (nouppercase: default): " << std::endl;
    std::cout << "pos_int (dec): " << std::dec << pos_int << std::endl;
    std::cout << "pos_int (hex): " << std::hex << pos_int << std::endl;
    std::cout << "pos_int (oct): " << std::oct << pos_int << std::endl;

    std::cout << std::endl;
    std::cout << "pos_int (uppercase): " << std::endl;
    std::cout << std::uppercase;
    std::cout << "pos_int (dec): " << std::dec << pos_int << std::endl;
    std::cout << "pos_int (hex): " << std::hex << pos_int << std::endl;
    std::cout << "pos_int (oct): " << std::oct << pos_int << std::endl;


    //===================================================================
    std::cout << std::endl;


    //fixed and scientific : for floating point values

    double a{ 3.1415926535897932384626433832795 };
    double b{ 2006.0 };
    double c{ 1.34e-10 };

    std::cout << std::endl;
    std::cout << "double values (default: use scientific where necessary): " << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    std::cout << std::endl;
    std::cout << "double values (fixed): " << std::endl;
    std::cout << std::fixed;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    std::cout << std::endl;
    std::cout << "double values (scientific): " << std::endl;
    std::cout << std::scientific;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    std::cout << std::endl;
    std::cout << "double values (back to defaults): " << std::endl;
    std::cout.unsetf(std::ios::scientific | std::ios::fixed); // Hack
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;


    //===================================================================
    std::cout << std::endl;

    //setprecision() : the number of digits printed out for a floating point. Default is 6

    a = 3.1415926535897932384626433832795;

    std::cout << std::endl;
    std::cout << "a (default precision(6)): " << a << std::endl;
    std::cout << std::setprecision(10);
    std::cout << "a (precision(10)): " << a << std::endl;
    std::cout << std::setprecision(20);
    std::cout << "a (precision(20)): " << a << std::endl;

    //If the precision is bigger than supported by the type, you'll just print garbage.

    //===================================================================
    std::cout << std::endl;


    //showpoint and noshowpoint : show trailing zeros if necessary
    //Force output of the decimal point

    double d{ 34.1 };
    double e{ 101.99 };
    double f{ 12.0 };
    int    g{ 45 };

    std::cout << std::endl;
    std::cout << "noshowpoint (default): " << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl; // 12
    std::cout << "g: " << g << std::endl;

    std::cout << std::endl;
    std::cout << "showpoint: " << std::endl;
    std::cout << std::showpoint;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl; // 12.0
    std::cout << "g: " << g << std::endl;

	return 0;
}