#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class Book
{
	friend std::ostream& operator<<(std::ostream& out, const Book& operand);
public:
	Book(int year, std::string_view title) : m_year(year), m_title(title) {}
	Book() {}

	bool operator==(const Book& right_operand) const
	{
		return this->m_year == right_operand.m_year;
	}

	std::partial_ordering operator<=>(const Book& right_operand) const
	{
		if (this->m_year > right_operand.m_year)
			return std::partial_ordering::greater;
		else if (this->m_year == right_operand.m_year)
			return std::partial_ordering::equivalent;
		else if (this->m_year < right_operand.m_year)
			return std::partial_ordering::less;
		else
			return std::partial_ordering::unordered;
	}

	int get_year() const { return m_year; }
	std::string get_title() const { return m_title; }

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
void print_collection(const T& collection)
{
	std::cout << "collection [";
	for (const auto& e : collection)
		std::cout << " " << e;
	std::cout << " ]" << std::endl;
}

int main()
{
	// Directly without predicate
	std::vector<int> collection{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };
	//std::list<int> collection{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 }; // std::sort() - Compiler Error, std::list doesn't have a random access iterator

	std::cout << "collection(unsorted): ";
	print_collection(collection);

	std::sort(std::begin(collection), std::end(collection));

	std::cout << "collection(sorted): ";
	print_collection(collection);

	std::cout << "\n==================================================\n\n";

	// With custom compare function
	collection = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

	std::cout << "collection(unsorted): ";
	print_collection(collection);

	//std::sort(std::begin(collection), std::end(collection), std::less<int>());
	std::sort(std::begin(collection), std::end(collection), std::greater<int>());
	//std::sort(std::begin(collection), std::end(collection), [](int x, int y) {return x < y; });

	std::cout << "collection(sorted): ";
	print_collection(collection);

	std::cout << "\n==================================================\n\n";

	// Sorting collection of custom items
	std::vector<Book> books
	{
		Book(1734, "Cooking Food"),
		Book(2000, "Building Computers"),
		Book(1995, "Farming for Beginners")
	};

	std::cout << "books(before sort):" << std::endl;
	print_collection(books);

	// Will look for operator<. Put it in and makes the compiler happy
	//std::sort(std::begin(books), std::end(books));
	//std::sort(std::begin(books), std::end(books), std::less<Book>());
	//std::sort(std::begin(books), std::end(books), std::greater<Book>());

	// Use a lambda to sort by title
	auto cmp = [](const Book& book1, const Book& book2)
	{
		return book1.get_title() < book2.get_title();
	};
	std::sort(std::begin(books), std::end(books), cmp);
	

	std::cout << "books(after sort):" << std::endl;
	print_collection(books);



	return 0;
}