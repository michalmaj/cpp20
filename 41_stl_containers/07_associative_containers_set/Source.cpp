#include <iostream>
#include <set>
#include <functional>

class Book
{
	friend std::ostream& operator<<(std::ostream& out, const Book& operand);
public:
	Book(int year, std::string title) : m_year(year), m_title(title){}

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
void print_collection(const T& collection)
{
	auto it = collection.begin();

	std::cout << "Collection [";
	while (it != collection.end())
	{
		std::cout << " " << *it;
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
	// Code1: Building sets
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "building sets (Need < operator for ordering):" << std::endl;

	std::set<int> numbers{ 11, 16, 2, 912, 15, 6, 15, 2 }; // Data is ordered internally, no duplicates
	print_collection(numbers);

	// Set of custom types: need to implement operator<
	std::set<Book> books{ Book(2000, "Cooking Food"),
		Book(1930, "Building Computers"), Book(1995, "Farming for beginners") };
	print_collection(books);

	// Code2: Iterators
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Iterators:" << std::endl;

	auto it = numbers.begin();
	std::cout << "set of numbers: [";
	while (it != numbers.end())
	{
		std::cout << " " << *it;
		++it;
	}
	std::cout << "]" << std::endl;

	auto it_back = numbers.rbegin();
	std::cout << "set of numbers(reverse): [";
	while (it_back != numbers.rend())
	{
		std::cout << " " << *it_back;
		++it_back;
	}
	std::cout << "]" << std::endl;

	auto it_back_books = books.rbegin();
	std::cout << "set of books(reverse): [";
	while (it_back_books != books.rend())
	{
		std::cout << " " << *it_back_books;
		++it_back_books;
	}
	std::cout << "]" << std::endl;

	// Code3: Capacity
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Capacity:" << std::endl;

	std::cout << "numbers: ";
	print_collection(numbers);
	std::cout << "set max_size: " << numbers.max_size() << std::endl;
	std::cout << "set is empty: " << std::boolalpha << numbers.empty() << std::endl;
	std::cout << "set size: " << numbers.size() << std::endl;

	// Code4: Clear
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Clear:" << std::endl;

	print_collection(numbers);

	numbers.clear();

	print_collection(numbers);
	std::cout << "set is empty: " << std::boolalpha << numbers.empty() << std::endl;

	// Code5: Insert
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Insert:" << std::endl;

	numbers = { 11, 12, 13, 14, 15 };
	print_collection(numbers);

	// Insert 14: won't insert because std::set doesn't allow duplicates
	// Will just do nothing adn won't give an error though.
	numbers.insert(14);

	std::cout << "After insert 14: ";
	print_collection(numbers);

	// Can capture the insert result through a returned std::pair object.
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	auto result = numbers.insert(20);
	std::cout << "first: " << *result.first << std::endl;
	std::cout << "second: " << result.second << std::endl;

	result = numbers.insert(14);
	std::cout << "first: " << *result.first << std::endl;
	std::cout << "second: " << result.second << std::endl;

	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	if (result.second)
		std::cout << "Insertion of: " << *result.first << std::endl;
	else
		std::cout << "Couldn't insert: " << *result.first << std::endl;

	// Code6: Emplace
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Emplace:" << std::endl;

	print_collection(numbers);

	auto result_emplace = numbers.emplace(421); // Success
	//auto result_emplace = numbers.emplace(13); // Fail

	if (result_emplace.second)
		std::cout << "Emplace of: " << *result_emplace.first << " successful" << std::endl;
	else
		std::cout << "Emplace of: " << *result_emplace.first << " FAILED" << std::endl;

	print_collection(numbers);

	// Code6: Erase
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Erase:" << std::endl;

	print_collection(numbers);

	auto it_erase = std::find(numbers.begin(), numbers.end(), 13);

	if (it_erase != numbers.end())
		std::cout << "Found 13!" << std::endl;
	else
		std::cout << "Couldn't find 13!" << std::endl;

	// Erase 13
	if (it_erase != numbers.end())
		numbers.erase(it_erase);

	print_collection(numbers);

	// Code7: Swap
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Swap:" << std::endl;


	std::set<int> other_numbers{ 200, 400, 600 };

	std::cout << "numbers: ";
	print_collection(numbers);
	std::cout << "other_numbers: ";
	print_collection(other_numbers);

	numbers.swap(other_numbers);

	std::cout << "numbers: ";
	print_collection(numbers);
	std::cout << "other_numbers: ";
	print_collection(other_numbers);

	// Code8: Change comparator
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Change comparator:" << std::endl;

	//std::set<int> numbers1{ 11, 16, 2, 9, 12, 15, 6, 15, 2 }; // Use default functor (std::less)
	//std::set<int, std::less<int>> numbers1{ 11, 16, 2, 9, 12, 15, 6, 15, 2 }; // Built-in functor
	//std::set<int, std::greater<int>> numbers1{ 11, 16, 2, 9, 12, 15, 6, 15, 2 }; // Built-in functor
	//std::set<int, IntComparator> numbers1{ 11, 16, 2, 9, 12, 15, 6, 15, 2 }; // Use custom functor

	//// Function pointer
	//std::set<int, bool(*)(int, int)> numbers1(compare_ints);
	//numbers1.insert({ 11, 16, 2, 9, 12, 15, 6, 15, 2 });

	std::set<int, std::function<bool(int, int)>> numbers1([](int left, int right)
		{
			return left > right;
		}); // Lambda function
	numbers1.insert({ 11, 16, 2, 9, 12, 15, 6, 15, 2 });

	print_collection(numbers1);

	return 0;
}