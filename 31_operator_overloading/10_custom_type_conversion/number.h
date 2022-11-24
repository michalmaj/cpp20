#pragma once

#include <iostream>
#include "point.h"

class Number
{
	friend std::ostream& operator<<(std::ostream& out, const Number& n);

	// Arithmetic operators
	friend Number operator+(const Number& left, const Number& right);
	friend Number operator-(const Number& left, const Number& right);
	friend Number operator*(const Number& left, const Number& right);
	friend Number operator/(const Number& left, const Number& right);
	friend Number operator%(const Number& left, const Number& right);


public:
	Number() = default;
	Number(int value);
	~Number() = default;

	// getter
	int get_wrapped_int() const
	{
		return m_wrapped_int;
	}

	// Custom type conversion
	// If we mark them as explicit we have to use a static_cast to explicitly show the type
	explicit operator double() const
	{
		return static_cast<double>(m_wrapped_int);
	}

	explicit operator Point() const
	{
		return Point{ static_cast<double>(m_wrapped_int), static_cast<double>(m_wrapped_int) };
	}

private:
	int m_wrapped_int;
};

