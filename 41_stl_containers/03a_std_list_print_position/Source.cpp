#include <iostream>
#include <list>

template <typename T, typename P>
void print_positions(const T& l, const P& p)
{
	for (const auto& e : p)
	{
		auto it = l.begin();
		auto i = e;
		while(i != 0)
		{
			++it;
			--i;
		}
		std::cout << "[" << e << "]:" << *it << std::endl;
	}

}

int main()
{
	std::list<int> l1 = { 7, 5, 16, 8,11,34,78 };
	std::list<unsigned int> p1 = { 1,3,5,2,0 };
	print_positions(l1, p1);


	std::list<std::string> l = { "She","is","the","queen","of","the","blue","sky" };
	std::list<unsigned int> p = { 2,7,1,6 };
	print_positions(l, p);

	return 0;
}