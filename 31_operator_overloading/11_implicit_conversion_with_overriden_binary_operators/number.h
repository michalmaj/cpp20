#pragma once

#include <iostream>


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
	Number(int value); // explicit key-word prevents to use it as a implicit conversion for int type
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

	//// Can't do a implicit conversion
	//Number operator+(const Number& right) const
	//{
	//	return { m_wrapped_int + right.m_wrapped_int };
	//}
	

private:
	int m_wrapped_int;
};

