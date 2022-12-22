#pragma once

#include <iostream>
#include <string_view>

class SomethingIsWrong
{
public:
	SomethingIsWrong(std::string_view s) : m_message(s) {}

	// Copy constructor
	SomethingIsWrong(const SomethingIsWrong& source)
	{
		std::cout << "Copy constructor for SomethingIsWrong called" << std::endl;
		m_message = source.m_message;
	}

	// Destructor
	~SomethingIsWrong()
	{
		std::cout << "SomethingIsWrong destructor called" << std::endl;
	}

	std::string what() const
	{
		return m_message;
	}

protected:
	std::string m_message;
};

class Warning : public SomethingIsWrong
{
public:
	Warning(std::string_view s) : SomethingIsWrong(s){}
	std::string what() const { return m_message + " Yellow"; }
};

class SmallError : public Warning
{
public:
	SmallError(std::string_view s) : Warning(s){}
	std::string what() const { return m_message + " Orange"; }
};

class CriticalError : public SmallError
{
public:
	CriticalError(std::string_view s) : SmallError(s){}
	std::string what() const { return m_message + " Red"; }
};