#pragma once

#include <iostream>
#include <string_view>

class Shape
{
public:
	Shape();
	Shape(std::string_view description);
	~Shape();

	virtual int get_count() const
	{
		return m_count;
	}

	inline static int m_count{ 0 }; // C++17 version of initializing static variables (inline keyword)

protected:
	std::string m_description;
};

