#pragma once

#pragma warning(disable:4996)
#include <iostream>
#include <cstring>

// Regular class template
template <typename T>
class Adder
{
public:
	Adder() = default;
	T add(T x, T y);
	void do_something()
	{
		std::cout << "Doing something..." << std::endl;
	}
};

template <typename T>
T Adder<T>::add(T x, T y)
{
	return x + y;
}

// Template specialization
template <>
class Adder <char*>
{
public:
	Adder() = default;
	char* add(char* a, char* b);

	void do_something()
	{
		std::cout << "Doing something..." << std::endl;
	}
};

//template <> // this is not needed if defined outside of class
inline char* Adder<char*>::add(char* a, char* b)
{
	return strcat(a, b);
}
