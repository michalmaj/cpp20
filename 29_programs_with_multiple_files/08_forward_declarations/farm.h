#pragma once

class Dog; // forward declaration

class Farm
{
public:
	Farm() = default;
	~Farm() = default;

	void use_dog(const Dog& dog_param); // Doesn't require the definition

	//void do_something(const Dog& dog_param)
	//{
	//	dog_param.print_info(); // requires 'dog.h'
	//}

private:
	//Dog dog_memebr; // requires 'dog.h'
};

