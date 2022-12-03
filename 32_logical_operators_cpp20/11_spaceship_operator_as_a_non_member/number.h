#pragma once

#include <compare>
#include <iostream>
#include <compare>

class Number
{
	friend std::ostream& operator<<(std::ostream& out, const Number& number);

public:
	Number() = delete;
	explicit Number(int value) : m_wrapped_int(value) {}

	// getter
	int get_wrapped_int() const
	{
		return m_wrapped_int;
	}

	//auto operator<=>(const Number& right) const = default;
	//auto operator<=>(int n) const
	//{
	//	return m_wrapped_int <=> n;
	//}

	//bool operator==(const Number& right) const
	//{
	//	return m_wrapped_int == right.m_wrapped_int;
	//}

	//bool operator==(int n) const
	//{
	//	return m_wrapped_int == n;
	//}

private:
	int m_wrapped_int{};
};


inline auto operator<=>(const Number& left, const Number& right)
{
	return left.get_wrapped_int() <=> right.get_wrapped_int();
}

inline auto operator<=>(int left, const Number& right)
{
	return left <=> right.get_wrapped_int();
}

inline bool operator==(const Number& left, const Number& right)
{
	return left.get_wrapped_int() == right.get_wrapped_int();
}

inline bool operator==(int left, const Number& right)
{
	return left == right.get_wrapped_int();
}
