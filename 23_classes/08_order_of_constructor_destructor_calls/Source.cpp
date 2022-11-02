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



int main()
{
	Dog my_dog1{ "Doggy1", "Shepherd", 2 };
	Dog my_dog2{ "Doggy2", "Shepherd", 3 };
	Dog my_dog3{ "Doggy3", "Shepherd", 5 };
	Dog my_dog4{ "Doggy4", "Shepherd", 1 };


	return 0;
}