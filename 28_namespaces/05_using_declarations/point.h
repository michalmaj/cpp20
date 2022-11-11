#pragma once

#include <iostream>

namespace Geom
{
	class Point
	{
	public:
		Point();
		Point(double x, double y);
		void print_info() const
		{
			std::cout << "Point [x: " << m_x << ", y: " << m_y << "]" << std::endl;
		}
		~Point();

	private:
		double m_x;
		double m_y;
	};
}

