#include <iostream>

class Item
{
public:
	Item(int a, int b) : m_var1(a), m_var2(b){}

	void some_member_func()
	{
		auto func = [&]() // We can capture by this keyword or by reference &
		{
			std::cout << "member vars: " << m_var1 << "," << m_var2 << std::endl;
		};
		func();
	}
private:
	int m_var1;
	int m_var2;
};

int main()
{
	Item item{ 10, 20 };

	return 0;
}