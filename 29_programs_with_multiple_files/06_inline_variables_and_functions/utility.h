#pragma once

#include <iostream>

inline double threshold{ 11.1 };

inline double add(double a, double b)
{
	if ((a > 11.1) and (b > 11.1))
		return a + b;
	return threshold;
}