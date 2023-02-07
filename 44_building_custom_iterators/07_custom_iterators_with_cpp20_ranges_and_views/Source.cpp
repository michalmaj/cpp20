#include <vector>
#include <ranges>
#include <algorithm>
#include "boxcontainer.h"

void print(auto view)
{
	for (auto i : view) // Computation happens here 
		std::cout << i << " ";
	std::cout << std::endl;
}

struct Student
{
	friend std::ostream& operator<<(std::ostream& out, const Student& s)
	{
		out << "Student [name: " << s.m_name << ", age: " << s.m_age << "]";
		return out;
	}

	auto operator<=>(const Student&) const = default;
	std::string m_name;
	unsigned int m_age;
};

int main()
{
	BoxContainer<int> vi{ 5, 1, 4, 8, 5, 3, 7, 9, 6 };

	// std::ranges::filter_view - filter our data by given predicate
	std::cout << std::endl;
	std::cout << "std::ranges::filter_view:" << std::endl;

	auto evens = [](int i) {return i % 2 == 0; };

	std::cout << "vi: ";
	print(vi);

	std::ranges::filter_view v_evens = std::ranges::filter_view(vi, evens); // No computations
	std::cout << "vi evens: ";
	print(v_evens);

	// Print evens on the fly
	std::cout << "vi evens: ";
	print(std::ranges::filter_view(vi, evens));

	// std::ranges::transform_view - transform data by given function
	std::cout << std::endl;
	std::cout << "std::ranges::transform_view:" << std::endl;

	std::ranges::transform_view v_transformed = std::ranges::transform_view(vi,
		[](int i) {return i * 10; });

	std::cout << "vi: ";
	print(vi);
	std::cout << "vi transformed: ";
	print(v_transformed);

	// std::ranges::take_view - get n first values from collection
	std::cout << std::endl;
	std::cout << "std::ranges::take_view:" << std::endl;

	std::ranges::take_view v_taken = std::ranges::take_view(vi, 5);

	std::cout << "vi: ";
	print(vi);
	std::cout << "vi taken: ";
	print(v_taken);


	// std::ranges::take_while_view - get values from collection until predicate is true
	std::cout << std::endl;
	std::cout << "std::ranges::take_while_view:" << std::endl;

	std::ranges::take_while_view v_taken_while = std::ranges::take_while_view(vi,
		[](int i) {return i % 2 != 0; });

	std::cout << "vi: ";
	print(vi);
	std::cout << "vi taken while: ";
	print(v_taken_while);

	// std::ranges::drop_view - drop n first elements
	std::cout << std::endl;
	std::cout << "std::ranges::drop_view:" << std::endl;

	std::ranges::drop_view v_drop = std::ranges::drop_view(vi, 5);

	std::cout << "vi: ";
	print(vi);
	std::cout << "vi drop: ";
	print(v_drop);

	// std::ranges::drop_while_view - drop elements as long as the predicate is met
	std::cout << std::endl;
	std::cout << "std::ranges::drop_while_view:" << std::endl;

	std::ranges::drop_while_view v_drop_while = std::ranges::drop_while_view(vi,
		[](int i) {return i % 2 != 0; });

	std::cout << "vi: ";
	print(vi);
	std::cout << "vi drop while: ";
	print(v_drop_while);



	// Range adaptors
	// std::view_filter
	std::cout << std::endl;
	std::cout << "std::views::filter:" << std::endl;
	auto evens1 = [](int i) {return i % 2 == 0; };

	std::ranges::filter_view v_evens1 = std::views::filter(vi, evens1);

	std::cout << "vi: ";
	print(vi);
	std::cout << "vi evens: ";
	print(v_evens1);

	// Students example
	std::cout << std::endl;
	std::cout << "Students example:" << std::endl;

	BoxContainer<Student> class_room{ {"Mike", 12}, {"John", 17}, {"Drake", 14}, {"Mary", 16} };

	std::cout << std::endl;
	std::cout << "classroom:" << std::endl;
	for (auto& s : class_room)
		std::cout << " " << s << std::endl;

	std::ranges::sort(class_room, std::less<>{}, & Student::m_age);

	std::cout << "classroom(after sort):" << std::endl;
	for (auto& s : class_room)
		std::cout << " " << s << std::endl;

	std::cout << "students under 15 : ";
	print(std::views::take_while(class_room, [](const Student& s) {return (s.m_age < 15); }));










	return 0;
}