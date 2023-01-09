#include "boxcontainer.h"

class Item
{
	friend std::ostream& operator<<(std::ostream& out, const Item& operand);

public:
	Item() : m_data(new int) {}
	Item(int value) : m_data(new int{ value }) {}
	~Item() { delete m_data; }

	// Copy members
	Item(const Item& source) : m_data(new int)
	{
		std::cout << "Item copy constructor copying data..." << std::endl;
		*m_data = *source.m_data;
	}

	Item& operator=(const Item& right_operand)
	{
		std::cout << "Item copy assignment operator copying data..." << std::endl;
		if (&right_operand != this)
			*m_data = *right_operand.m_data;

		return *this;
	}

	// Move members
	Item(Item&& source)
	{
		std::cout << "Item move constructor moving data..." << std::endl;

		// Steal the pointer
		m_data = source.m_data;

		// Invalidate (reset) the source pointer
		source.m_data = nullptr;
	}

	Item& operator=(Item&& right_operand)
	{
		std::cout << "Item move assignment operator moving data..." << std::endl;

		if(&right_operand != this)
		{
			// Steal the pointer
			m_data = right_operand.m_data;

			// Reset (invalidate) source pointer
			right_operand.m_data = nullptr;
		}

		return *this;
	}

private:
	int* m_data{ nullptr };
};

std::ostream& operator<<(std::ostream& out, const Item& operand)
{
	out << "Item : [" << (*operand.m_data) << "]";
	return out;
}


Item get_value()
{
	//return Item(22);
	return { 22 }; // Newer better version
}

void do_something(Item&& item)
{
	std::cout << "Do something move version called..." << std::endl;
	//Item internal = item; // Copy constructor
	Item internal = std::move(item); // Move constructor
	std::cout << "internal: " << internal << std::endl;
}

int main()
{
	Item&& rvalue_ref{ get_value() };

	Item item1(rvalue_ref); // Copy constructor - our rvalue is now a lvalue
	Item item2{ std::move(rvalue_ref) }; // We can force compiler to treat as rvalue - move constructor called

	std::cout << "------------------------------------------" << std::endl;

	rvalue_ref = get_value();
	do_something(std::move(rvalue_ref));

	std::cout << "------------------------------------------" << std::endl;

	BoxContainer<Item> items;
	items.add(get_value()); // Item copy assignment operator
	items.add(std::move(get_value())); // Item move assignment operator

	return 0;
}