#include <iostream>
#include <string_view>
#include <stack>
#include <vector>
#include <list>
#include <deque>

class Book
{
	friend std::ostream& operator<<(std::ostream& out, const Book& operand);
public:
	Book(int year, std::string_view title) : m_year(year), m_title(title) {}
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

//// We need to change those functions if we want to use std::vector and std::list as underlying container
//template <typename T>
//void print_stack(std::stack<T> stack)
//{
//	// Notice that we are working on a copy here - IMPORTANT
//	std::cout << "stack of elements: [";
//	while(!stack.empty())
//	{
//		T item = stack.top();
//		std::cout << " " << item;
//		stack.pop(); // Popping from a copy doesn't affect the original. We are good here
//	}
//	std::cout << " ]" << std::endl;
//}
//
//template <typename T>
//void clear_stack(std::stack<T>& stack)
//{
//	std::cout << "Clearing stack of size: " << stack.size() << std::endl;
//
//	while (!stack.empty())
//		stack.pop();
//}

template <typename T, typename  Container=std::deque<T>>
void print_stack(std::stack<T, Container> stack)
{
	// Notice that we are working on a copy here - IMPORTANT
	std::cout << "stack of elements: [";
	while (!stack.empty())
	{
		T item = stack.top();
		std::cout << " " << item;
		stack.pop(); // Popping from a copy doesn't affect the original. We are good here
	}
	std::cout << " ]" << std::endl;
}

template <typename T, typename Container=std::deque<T>>
void clear_stack(std::stack<T, Container>& stack)
{
	std::cout << "Clearing stack of size: " << stack.size() << std::endl;

	while (!stack.empty())
		stack.pop();
}


int main()
{
	// Code1: Creating std::stack and storing data in
	std::cout << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Creating std::stack:" << std::endl;

	std::stack<int> numbers1;

	std::cout << "numbers1: ";
	print_stack(numbers1);

	numbers1.push(10);
	numbers1.push(20);
	numbers1.push(30);

	std::cout << "numbers1: ";
	print_stack(numbers1); // 30 20 10 - FILO (first in last out)

	numbers1.push(40);
	numbers1.push(50);

	std::cout << "numbers1: ";
	print_stack(numbers1); // 50 40 30 20 10 - FILO (first in last out)

	// Code2: Accessing and removing elements
	std::cout << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Accessing and removing elements:" << std::endl;

	// Accessing
	std::cout << "top: " << numbers1.top() << std::endl;

	// Pop off the top
	print_stack(numbers1);
	numbers1.pop();
	print_stack(numbers1);
	std::cout << "top: " << numbers1.top() << std::endl;

	// We can organize these calls to top and pop into a function
	// that can nicely show the contents of a stack. That's what print_stack does.

	// Code3: Modifying the top element through the reference returned by top()
	// top() returns a reference. We can use that to modify the underlying
	// element in the stack.
	std::cout << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Modifying the top element through the reference returned by top():" << std::endl;

	std::cout << "numbers1: ";
	print_stack(numbers1);

	numbers1.top() = 55;

	std::cout << "numbers1: ";
	print_stack(numbers1);

	// Code4: Clearing a stack
	std::cout << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Clearing a stack:" << std::endl;

	std::cout << "stack initial size: " << numbers1.size() << std::endl;
	std::cout << "numbers1 (before): ";
	print_stack(numbers1);

	clear_stack(numbers1);

	std::cout << "stack initial size: " << numbers1.size() << std::endl;
	std::cout << "numbers1 (after): ";
	print_stack(numbers1);

	// Code5: Stack of user defined types
	std::cout << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Stack of user defined types:" << std::endl;

	std::stack<Book> books;
	books.push(Book{ 1921, "The Art of War" });
	books.push(Book{ 2000, "Social Media Marketing" });
	books.push(Book{ 2022, "How the Pandemic Changed THe World" });

	std::cout << "books: ";
	print_stack(books);
	std::cout << "books size: " << books.size() << std::endl;

	// Code6: Custom underlying sequence container
	std::cout << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Custom underlying sequence container:" << std::endl;

	std::stack<int, std::vector<int>> numbers2;
	std::stack<int, std::list<int>> numbers3;
	std::stack<int, std::deque<int>> numbers4;

	numbers2.push(5); // underlying container: std::vector 
	numbers2.push(6);

	numbers3.push(7); // underlying container: std::list
	numbers3.push(8);

	numbers4.push(9); // underlying container: std::deque 
	numbers4.push(10);

	std::cout << "numbers4: ";
	print_stack(numbers4); // OK

	std::cout << "numbers3: ";
	print_stack(numbers3); // Compiler Error we have to edit our print function

	std::cout << "numbers2: ";
	print_stack(numbers2);









	return 0;
}