/*
 * Alternative way for several different condition.
 *
 *  Condition for switch can be only integral types: int, long, short, etc.
 *
 * Why we need to use a break statement after every case in switch?
 * The break statement after each case is very important. It stops processing the switch
 * block when a successful case has been found. If the break case is not there, all the
 * cases following the current case will be executed.
 */

#include <iostream>

 // Tools
struct Tools
{
    const int Pen{ 10 };
    const int Marker{ 20 };
    const int Eraser{ 30 };
    const int Rectangle{ 40 };
    const int Circle{ 50 };
    const int Ellipse{ 60 };
};

int main()
{
    // Must be constexpr, because case expression must be constant
    constexpr Tools tools;

    int tool{ tools.Eraser };

    switch (tool)
    {
	    case tools.Pen:
		    {
			    std::cout << "Active tool is Pen" << std::endl;
		    }
			break;
	    case tools.Marker:
		    {
			    std::cout << "Active tool is Marker" << std::endl;
		    }
			break;
	    case tools.Eraser:
		    {
			    std::cout << "Active tool is Eraser" << std::endl;
		    }
			break;
	    case tools.Rectangle:
		    {
			    std::cout << "Active tool is Rectangle" << std::endl;
		    }
			break;
	    case tools.Circle:
		    {
			    std::cout << "Active tool is Circle" << std::endl;
		    }
			break;
	    case tools.Ellipse:
		    {
			    std::cout << "Active tool is Ellipse" << std::endl;
		    }
			break;
		default:
			{
			std::cout << "No match found" << std::endl;
			}
			break;
    }

	std::cout << "Moving on" << std::endl;

	//// For example std::string can't be used in switch statement
	//std::string name{ "John" };
 //   switch (name)
 //   {
	//    
 //   }

	return 0;
}