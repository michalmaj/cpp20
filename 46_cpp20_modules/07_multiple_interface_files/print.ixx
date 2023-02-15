module;

export module print;

// Module preamble
import <iostream>;
import <string>;

export
{
	void greet(const std::string& name);

	void print_name_length(const char* c_str_name);
}
