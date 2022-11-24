#include "number.h"

#include <cassert>

std::ostream& operator<<(std::ostream& out, const Number& n)
{
	out << "Number [" << n.m_wrapped_int << "]";
	return out;
}

// Arithmetic operators
Number operator+(const Number& left, const Number& right)
{
	return { left.m_wrapped_int + right.m_wrapped_int };
}

Number operator-(const Number& left, const Number& right)
{
	return { left.m_wrapped_int - right.m_wrapped_int };
}

Number operator*(const Number& left, const Number& right)
{
	return { left.m_wrapped_int * right.m_wrapped_int };
}

Number operator/(const Number& left, const Number& right)
{
	assert(right.m_wrapped_int != 0 && "Division by zero!");
	return { left.m_wrapped_int / right.m_wrapped_int };
}

Number operator%(const Number& left, const Number& right)
{
	assert(right.m_wrapped_int != 0 && "Division by zero!");
	return { left.m_wrapped_int % right.m_wrapped_int };
}

Number::Number(int value) : m_wrapped_int(value){}