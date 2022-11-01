#include <iostream>
#include <string_view>

class Dog
{
public:
	Dog() = default;
	Dog(std::string_view name_param, std::string_view breed_param, int age_param);
	~Dog();

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
	std::cout << "Dog constructor called for: " << name << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called for: " << name << std::endl;
	delete p_age;
}

void some_func()
{
	Dog my_dog{ "Millie", "Husky", 12 };
}

void some_other_func()
{
	Dog* p_dog = new Dog("Sherpa", "Malamute", 11);

	delete p_dog;
}


int main()
{
	Dog my_dog{ "Fluffy", "Shepherd", 2 };

	some_func();

	some_other_func();

	std::cout << "Done!\n";
	return 0;
}