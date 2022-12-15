#include <iostream>
#include <memory>
#include "animal.h"
#include "feline.h"
#include "dog.h"

int main()
{
	std::unique_ptr<Animal> p_animal = std::make_unique<Dog>(); // Without virtual keyword before destructor,
															    // only destructor for Animal will be called


	return 0;
}