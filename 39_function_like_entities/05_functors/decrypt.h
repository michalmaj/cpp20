#pragma once

// Functor or function object 
class Decrypt
{
public:
	char operator()(const char& param)
	{
		return static_cast<char>(param - 3);
	}
};