#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base constructor called" << std::endl;
		this->setup(); // Static binding kicks in here
	}

	virtual ~Base()
	{
		this->clean_up(); // Static binding kicks in here
		std::cout << "Base destructor called" << std::endl;
	}

	virtual void setup()
	{
		std::cout << "Base::setup() called" << std::endl;
		m_value = 10;
	}

	virtual void clean_up()
	{
		std::cout << "Base::clean_up() called" << std::endl;
	}

	int get_value() const
	{
		return m_value;
	}


protected:
	int m_value;
};

class Derived: public Base
{
public:
	Derived()
		: Base()
	{
		std::cout << "Derived constructor called" << std::endl;
	}

	virtual void setup() override
	{
		std::cout << "Derived::setup() called" << std::endl;
		m_value = 100;
	}

	virtual void clean_up() override
	{
		std::cout << "Derived::clean_up() called" << std::endl;
	}
};


int main()
{
	Base* p_base = new Derived;

	auto value = p_base->get_value();
	std::cout << "Value: " << value << std::endl; // 10, because setup() method is called from Base constructor

	p_base->clean_up();

	delete p_base;

	return 0;
}