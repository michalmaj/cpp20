#include <iostream>
#include <string_view>
#include <exception>


class Animal
{
public:
	Animal(std::string_view n) :m_name(n){}
	Animal() = default;
	virtual ~Animal() = default;

	virtual void breathe() const{}

protected:
	std::string m_name;
};

class Feline : public Animal
{
public:
	Feline(std::string_view n) : Animal(n){}
private:
	int m_speed;
};

int main()
{
	Animal animal;

	try
	{
		Feline& feline_ref = dynamic_cast<Feline&>(animal);
	}
	catch (std::exception& ex)
	{
		std::cout << "Something is wrong: " << ex.what() << std::endl;
	}

	std::cout << "END" << std::endl;

	return 0;
}