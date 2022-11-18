#include "dog.h"

Dog::Dog(std::string_view name) : dog_name(name)
{
	std::cout << "Constructor for " << dog_name << " called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor for " << dog_name << " called." << std::endl;
}
