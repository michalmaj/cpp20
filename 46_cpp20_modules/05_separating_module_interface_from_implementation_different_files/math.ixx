module;

// Global module fragment
#include <cstring> // C function includes must show up here
//#include <iostream> // Non C function includes can also be imported

export module math; // Module declaration

// Module preamble
import <iostream>;
import <string>;
import <cmath>;

// Module purview

export
{
	double add(double a, double b);

	void greet(const std::string& name);

	void print_name_length(const char* c_str_name);

	double dist(double x, double y);

	class Point
	{
	public:
		Point() = default;
		Point(double x, double y);
		friend std::ostream& operator<<(std::ostream& out, const Point& point)
		{
			out << "Point [x: " << point.m_x << ", y: " << point.m_y << "]";
			return out;
		}

	private:
		double m_x;
		double m_y;
	};
}

