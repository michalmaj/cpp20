#pragma once

#include <numbers>

namespace Geom
{
	class Cylinder
	{
	public:
		Cylinder(double base_rad, double height);

		double volume() const
		{
			return std::numbers::pi * m_base_rad * m_base_rad * m_height;
		}

	private:
		double m_base_rad{ 1 };
		double m_height{ 1 };
	};
}

