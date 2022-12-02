#pragma once

#include <compare>
#include <iostream>

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

	auto operator<=>(const Number& right) const = default;
	auto operator<=>(int n) const
	{
		return m_wrapped_int <=> n;
	}

	bool operator==(const Number& right) const
	{
		return m_wrapped_int == right.m_wrapped_int;
	}

	bool operator==(int n) const
	{
		return m_wrapped_int == n;
	}

private:
	int m_wrapped_int{};
};

