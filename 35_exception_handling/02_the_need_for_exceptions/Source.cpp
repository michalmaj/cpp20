// Exceptions allow us to recover from these errors and give our program a chance to continue running
#include <iostream>

class Animal
{
public:
	Animal() = default;
	virtual ~Animal() = default;
	virtual void breathe() const{}
private:
	std::string m_description;
};

class Dog : public Animal
{
public:
	Dog() = default;
	virtual ~Dog() = default;

	virtual void breathe() const override{}
	void run() const
	{
		std::cout << "Dog running..." << std::endl;
	}

private:
	std::string m_fur_color;
};

// Function throws const char* exception when par_b is zero
int process_parameters(int par_a, int par_b)
{
	if (par_b == 0)
		throw "Potential division by 0 detected";
	return par_a / par_b;

}

int main()
{
	// int division by 0: CRASH	
	const int a{ 45 };
	const int b{ 0 };
	int result{};
	try
	{
		result = process_parameters(a, b);
	}catch (std::string ex)
	{
		std::cout << "Integer division by zero detected" << std::endl;
	}catch (int ex)
	{
		std::cout << "Something went wrong" << std::endl;
	}catch (const char* ex)
	{
		std::cout << "Exception: " << ex << std::endl;
	}

	std::cout << "\n=================================\n\n";

	// Downcast using dynamic_cast with references
	// The hierarchy of Animal->Dog has to be polymorphic to be able to do
	// this. This throws an exception because animal has no Dog part so the
	// cast won't really work.
	Animal animal;
	try
	{
		Dog& dog{ dynamic_cast<Dog&>(animal) };
	}catch (std::bad_cast& ex)
	{
		std::cout << "Something went wrong: " << ex.what() << std::endl;
	}
	

	std::cout << "Done!" << std::endl;

	return 0;
}