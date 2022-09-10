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

	switch (double strength{ 3.56 }; tool)
	{
	case tools.Pen:
	{
		std::cout << "Active tool is Pen, strength: " << strength << std::endl;
	}
	break;
	case tools.Marker:
	{
		std::cout << "Active tool is Marker, strength: " << strength << std::endl;
	}
	break;
	case tools.Eraser:
	{
		std::cout << "Active tool is Eraser, strength: " << strength << std::endl;
	}
	break;
	case tools.Rectangle:
	{
		std::cout << "Active tool is Rectangle, strength: " << strength << std::endl;
	}
	break;
	case tools.Circle:
	{
		std::cout << "Active tool is Circle, strength: " << strength << std::endl;
	}
	break;
	case tools.Ellipse:
	{
		std::cout << "Active tool is Ellipse, strength: " << strength << std::endl;
	}
	break;
	default:
	{
		std::cout << "No match found" << std::endl;
	}
	break;
	}

	std::cout << "Moving on" << std::endl;


	return 0;
}