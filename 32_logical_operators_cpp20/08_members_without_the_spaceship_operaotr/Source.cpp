#include <iostream>

struct Integer
{
	Integer() = default;
	Integer(int n) : m_wrapped_int(n){}

	int get() const
	{
		return m_wrapped_int;
	}

	bool operator==(const Integer& right) const
	{
		return (m_wrapped_int == right.m_wrapped_int);
	}

	bool operator<(const Integer& right) const
	{
		return (m_wrapped_int < right.m_wrapped_int);
	}

private:
	int m_wrapped_int{};
};

class Item
{
public:
	Item() = default;
	Item(int n) : Item(n, n, n){}
	Item(int a, int b, int c) :a{a}, b{b}, c{c}{}

	// Ordering: compiler generates >, <, >=, <= and also puts the == operator
	//auto operator<=>(const Item& right_operand) const = default;
	std::strong_ordering operator<=>(const Item& right_operand) const = default;

private:
	int a{ 1 };
	int b{ 2 };
	int c{ 3 };
	Integer d;
};

int main()
{
	Item i1{ 1, 2, 5 };
	Item i2{ 1, 2, 4 };

	std::cout << std::boolalpha;

	//auto result1 = (i1 > i2);
	auto result1 = ((i1 <=> i2) > 0); // A possible option for the compiler magic
	std::cout << " i1 > i2 : " << result1 << std::endl;
	//auto result2 = (i1 >= i2);
	auto result2 = ((i1 <=> i2) >= 0); // A possible option for the compiler magic
	std::cout << " i1 >= i2 : " << result2 << std::endl;

	auto result3 = (i1 == i2);
	std::cout << " i1 == i2 : " << result3 << std::endl;
	auto result4 = (i1 != i2);
	std::cout << " i1 != i2 : " << result4 << std::endl;

	//auto result5 = (i1 < i2);
	auto result5 = ((i1 <=> i2) < 0); // A possible option for the compiler magic
	std::cout << " i1 < i2 : " << result5 << std::endl;
	//auto result6 = (i1 <= i2);
	auto result6 = ((i1 <=> i2) <= 0); // A possible option for the compiler magic
	std::cout << " i1 <= i2 : " << result6 << std::endl;

	std::cout << "\n==========================================\n\n";

	//Implicit conversions

	auto result7 = (i1 > 20);
	auto result8 = (20 < i1);  // ( 20 <=> i1) < 0
	auto result9 = (i2 != 12);
	auto result10 = (12 != i2);

	std::cout << " i1 > 20 : " << result7 << std::endl;
	std::cout << " i20 < i1 : " << result8 << std::endl;
	std::cout << " i2 != 12 : " << result9 << std::endl;
	std::cout << " 12 != i2 : " << result10 << std::endl;
	return 0;
}