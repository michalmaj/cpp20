module;

// Global module: #include, preprocessor directives
#include <iostream>
export module my_math_module;
// Module preamble: import


// Module purview
export void say_something()
{
	std::cout << "saying say_something..." << std::endl;
}