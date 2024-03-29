#include <iostream>
#include <forward_list>

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

int main()
{
	std::forward_list<int> numbers{ 100, 2, 3, 4, 5 };
	print_collection(numbers);

	// Code1: element access
	std::cout << "front element: " << numbers.front() << std::endl;

	std::cout << "\n=========================================================\n\n";

	// Code2: modifiers
	std::cout << "modifiers:" << std::endl;

	// Clear
	std::cout << std::endl;
	std::cout << "clear:" << std::endl;
	print_collection(numbers);

	numbers.clear();

	print_collection(numbers);

	// Insert after
	std::cout << std::endl;
	std::cout << "insert_after:" << std::endl;
	numbers = { 11, 12, 13, 14, 15 };

	print_collection(numbers);

	auto it_insert = numbers.before_begin();

	numbers.insert_after(it_insert, 333);

	print_collection(numbers);

	// Emplace after: create in place after an iterator
	std::cout << std::endl;
	std::cout << "emplace_after:" << std::endl;

	it_insert = numbers.before_begin();

	numbers.emplace_after(it_insert, 444);

	print_collection(numbers);

	// Erase after
	std::cout << std::endl;
	std::cout << "erase_after:" << std::endl;

	auto it_erase = std::find(numbers.begin(), numbers.end(), 13);

	if (it_erase != numbers.end())
		std::cout << "Found 13!" << std::endl;
	else
		std::cout << "Couldn't find 13!" << std::endl;


	numbers.erase_after(it_erase); // number after 13 in our collection wil be erased
	print_collection(numbers);

	// Pop front
	std::cout << std::endl;
	std::cout << "pop_front:" << std::endl;

	numbers.pop_front();

	print_collection(numbers);

	// Resize up or down
	std::cout << std::endl;
	std::cout << "resize:" << std::endl;

	numbers.resize(10);

	print_collection(numbers);

	numbers.resize(3); // When we resize down, the elements are lost for good.
							   // If we resize up again, we won't get them back

	print_collection(numbers);

	numbers.resize(10);

	print_collection(numbers);

	// Swap
	std::cout << std::endl;
	std::cout << "swap:" << std::endl;

	std::forward_list<int> other_numbers{ 200, 400, 600 };

	std::cout << "numbers:" << std::endl;
	print_collection(numbers);

	std::cout << "other_numbers:" << std::endl;
	print_collection(other_numbers);

	numbers.swap(other_numbers);

	std::cout << "numbers:" << std::endl;
	print_collection(numbers);

	std::cout << "other_numbers:" << std::endl;
	print_collection(other_numbers);

	// Merge
	std::cout << std::endl;
	std::cout << "merge:" << std::endl;

	std::forward_list<int> numbers1{ 1, 5, 6 };
	std::forward_list<int> numbers2{ 9, 2, 4 };

	std::cout << "numbers1:" << std::endl;
	print_collection(numbers1);

	std::cout << "numbers2:" << std::endl;
	print_collection(numbers2);

	// Sort before merge
	numbers1.sort();
	numbers2.sort();

	numbers1.merge(numbers2);

	std::cout << "numbers1:" << std::endl;
	print_collection(numbers1);

	std::cout << "numbers2:" << std::endl;
	print_collection(numbers2);

	// splice_after: moving a range of elements from one container to another
	std::cout << std::endl;
	std::cout << "splice_after:" << std::endl;

	numbers1 = { 1, 5, 6, 8, 3 };
	numbers2 = { 9, 2, 4, 7, 13, 11, 17 };

	std::cout << "numbers1:" << std::endl;
	print_collection(numbers1);

	std::cout << "numbers2:" << std::endl;
	print_collection(numbers2);

	numbers1.splice_after(numbers1.before_begin(), numbers2, numbers2.before_begin(), numbers2.cend());

	std::cout << "numbers1:" << std::endl;
	print_collection(numbers1);

	std::cout << "numbers2:" << std::endl;
	print_collection(numbers2);

	// Remove
	std::cout << std::endl;
	std::cout << "remove:" << std::endl;

	numbers = { 1, 100, 2, 3, 10, 1, 11, -1, 12 };

	print_collection(numbers);

	numbers.remove(1); // remove both elements equal to 1

	print_collection(numbers);

	// Remove predicate
	std::cout << std::endl;
	std::cout << "remove predicate:" << std::endl;

	numbers.remove_if([](int n) {return n > 10; });

	print_collection(numbers);

	// Reverse
	std::cout << std::endl;
	std::cout << "revers:" << std::endl;

	numbers = { 1, 100, 2, 3, 10, 1, 11, -1, 12 };
	print_collection(numbers);

	numbers.reverse();
	print_collection(numbers);

	// Unique: removes contiguous duplicates
	std::cout << std::endl;
	std::cout << "unique:" << std::endl;

	numbers = { 1, 100, 100, 2, 3, 10, 1, 11, 11, -1, 12 , 10, 1 };

	print_collection(numbers);

	numbers.unique();

	print_collection(numbers);

	// Sort
	std::cout << std::endl;
	std::cout << "sort:" << std::endl;

	numbers.sort();

	print_collection(numbers);

	// If we want nto remove all duplicated, we can first sort and then
	// remove duplicates
	numbers.unique();

	print_collection(numbers);






	return 0;
}