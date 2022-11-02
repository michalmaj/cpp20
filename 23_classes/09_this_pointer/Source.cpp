/*
 * Each class member function contains a hidden pointer called
 * this. That pointer contains the address of the current object,
 * for which the method is being executed. This also applies to
 * constructors and destructor.
 */

#include <iostream>
#include <string_view>

class Dog
{
public:
	Dog() = default;
	Dog(std::string_view name_param, std::string_view breed_param, int age_param);
	~Dog();

	// Setters
	//// Chained calls using pointers
	//// We can return 'this' from setters to chain our setters
	//Dog* set_dog_name(std::string_view name)
	//{
	//	//name = name; // This does nothing
	//	this->name = name;
	//	return this;
	//}

	//Dog* set_dog_breed(std::string_view breed)
	//{
	//	this->breed = breed;
	//	return this;
	//}

	//Dog* set_dog_age(int age)
	//{
	//	*this->p_age = age;
	//	return this;
	//}

	// Chain calls using references
	Dog& set_dog_name(std::string_view name)
	{
		//name = name; // This does nothing
		this->name = name;
		return *this;
	}

	Dog& set_dog_breed(std::string_view breed)
	{
		this->breed = breed;
		return *this;
	}

	Dog& set_dog_age(int age)
	{
		*this->p_age = age;
		return *this;
	}

	// Methods
	void print_info() const
	{
		std::cout << "Dog (" << this << ") : [name: " << name << " breed: " << breed
			<< " age: " << *p_age << "]" << std::endl;
	}

private:
	std::string name;
	std::string breed;
	int* p_age{ nullptr };
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
	name = name_param;
	breed = breed_param;
	p_age = new int(age_param);
	std::cout << "Dog constructor called for: " << name << ", at: " << this << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called for: " << name << ", at: " << this << std::endl;
	delete p_age;
}



int main()
{
	Dog dog1{ "Fluffy", "Shepherd", 2 };
	dog1.print_info();

	//dog1.set_dog_name("Millie");
	//dog1.set_dog_breed("Husky");
	//dog1.set_dog_age(14);
	//dog1.print_info();

	//// Chained using pointers
	//dog1.set_dog_name("Millie")->set_dog_breed("Husky")->set_dog_age(14);
	//dog1.print_info();

	// Chained using references
	dog1.set_dog_name("Millie").set_dog_breed("Husky").set_dog_age(14);
	dog1.print_info();


	std::cout << "Done!\n";


	return 0;
}