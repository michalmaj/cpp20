#include <iostream>
#include <cassert>

struct Point
{
public:
	Point(std::initializer_list<double> list)
	{
		assert(list.size() == 2); // If the size of the list is not 2. Throw a runtime error.
		//std::cout << "Initializer list constructor called\n";
		//std::cout << "list size: " << list.size() << std::endl;

		//for(size_t i{}; i < list.size(); ++i)
		//{
		//	std::cout << "Element at index [" << i << "]: " << *(list.begin() + i) << std::endl;
		//}
		x = *(list.begin());
		y = *(list.begin() + 1);
	}

	void print_point() const
	{
		std::cout << "Point [x: " << x << ", y: " << y << "]" << std::endl;
	}
private:
	double x;
	double y;
};



int main()
{
	//Point p1{ 22.4, 65.4, 5.9, 6.8, 4.3, 5.6, 9.3, 4.3 };
	Point p1{ 22.4, 65.4 };
	p1.print_point();


	return 0;
}