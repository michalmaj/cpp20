#include <iostream>
#include <map>
#include <set>

class Book
{
	friend std::ostream& operator<<(std::ostream& out, const Book& operand);
public:
	Book(int year, std::string title) : m_year(year), m_title(title) {}
	Book() {}

	bool operator<(const Book& right_operand) const
	{
		return this->m_year < right_operand.m_year;
	}

private:
	int m_year;
	std::string m_title;
};

std::ostream& operator<<(std::ostream& out, const Book& operand)
{
	out << "Book [" << operand.m_year << ",  " << operand.m_title << "]";
	return out;
}

template <typename T>
void print_multiset(const std::multiset<T>& m_set)
{
	auto it = m_set.begin();

	std::cout << "multiset of elements: [";
	while(it != m_set.end())
	{
		std::cout << " " << *it;
		++it;
	}
	std::cout << " ]" << std::endl;
}

template <typename T, typename K>
void print_multimap(const std::multimap<T, K>& m_map)
{
	auto it = m_map.begin();

	std::cout << "multimap of elements: [";
	while(it != m_map.end())
	{
		std::cout << "[" << it->first << "," << it->second << "]";
		++it;
	}
	std::cout << " ]" << std::endl;	
}


// Comparator functor
class IntComparator
{
public:
	bool operator()(int left, int right) const
	{
		return left < right;
	}
};

// Comparator function pointer
bool compare_ints(int left, int right)
{
	return left < right;
}

int main()
{
	std::cout << "multiset:" << std::endl;

	std::multiset<int> numbers{ 1, 2, 1, 6, 2, 8, 3, 9, 4, 24, 6, 2 };
	std::multiset<Book> books{
		Book(1734, "Cooking Food"),
		Book(1930, "Building Computers"),
		Book(1734, "Farming for Beginners") };

	std::cout << "numbers: ";
	print_multiset(numbers);

	std::cout << "books: ";
	print_multiset(books);

	std::cout << std::endl;
	std::cout << "multimap:" << std::endl;

	std::multimap<int, std::string> office_numbers
	{
		std::make_pair(101, "Daniel Gray"),
		std::make_pair(102, "John Snow"),
		std::make_pair(103, "Jamie Lanister"),
		std::make_pair(102, "Van Gomir"),
		std::make_pair(101, "Kay Moris"),
		std::make_pair(102, "Zuba Loy"),
	};

	std::cout << "office_numbers: ";
	print_multimap(office_numbers);

	std::multimap<int, Book> other_books
	{
		{0, Book(1734, "Cooking Food")},
		{1, Book(1930, "Building Computers")},
		{1, Book(1734, "Farming for Beginners")}
	};
	std::cout << "other_books: ";
	print_multimap(other_books);




	return 0;
}