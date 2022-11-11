#pragma once

#include "point.h"

namespace Geom
{
	class Line
	{
	public:
		Line(const Point& start, const Point& end);

		void print_info() const
		{
			std::cout << "Line from:\n";
			m_start.print_info();
			std::cout << "to:\n";
			m_end.print_info();
		}

	private:
		Point m_start;
		Point m_end;
	};
}

