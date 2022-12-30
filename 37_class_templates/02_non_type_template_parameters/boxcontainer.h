#pragma once

#include <iostream>

template<typename T, size_t maximum>
class BoxContainer
{
	static constexpr size_t DEFAULT_CAPACITY{ 5 };
	static constexpr size_t EXPAND_STEPS{ 5 };

public:
	BoxContainer(size_t capacity = DEFAULT_CAPACITY);
	BoxContainer(const BoxContainer& source);
	~BoxContainer();

	// Helper getter methods
	size_t size() const { return m_size; }
	size_t capacity() const { return m_capacity; }

	T get_item(size_t index) const
	{
		return m_items[index];
	}

	// Method to add items to the box
	void add(const T& item);

	// Method to remove item or items
	bool remove_item(const T& item);
	size_t remove_all(const T& item);

	// In class operators
	void operator+=(const BoxContainer& operand);
	void operator=(const BoxContainer& source);

private:
	T* m_items;
	size_t m_size;
	size_t m_capacity;

	// Method to expand capacity
	void expand(size_t new_capacity);
};

// Free operators
template <typename T, size_t maximum>
BoxContainer<T, maximum> operator+(const BoxContainer<T, maximum>& left, const BoxContainer<T, maximum>& right);

template <typename T, size_t maximum>
inline std::ostream& operator<<(std::ostream& out, const BoxContainer<T, maximum>& operand)
{
	out << "BoxContainer [size: " << operand.size() << ", capacity: " << operand.capacity() << ", items: ";
	for (size_t i{ 0 }; i < operand.size(); ++i)
		out << operand.get_item(i) << " ";
	out << "]";

	return out;
}

// Definitions must be in the header file
template <typename T, size_t maximum>
BoxContainer<T, maximum>::BoxContainer(size_t capacity)
{
	m_items = new T[capacity];
	m_capacity = capacity;
	m_size = 0;
}

template <typename T, size_t maximum>
BoxContainer<T, maximum>::BoxContainer(const BoxContainer& source)
{
	// Delete old box
	delete[] m_items;
	// Set up new box
	m_items = new T[source.m_capacity];
	m_capacity = source.m_capacity;
	m_size = source.m_size;

	// Copy the items over from source
	for (size_t i{ 0 }; i < source.size(); ++i)
		m_items[i] = source.m_items[i];
}

template <typename T, size_t maximum>
BoxContainer<T, maximum>::~BoxContainer()
{
	delete[] m_items;
}

template <typename T, size_t maximum>
void BoxContainer<T, maximum>::expand(size_t new_capacity)
{
	std::cout << "Expanding to " << new_capacity << std::endl;
	T* new_items_container;
	if (new_capacity <= m_capacity)
		return; // The needed capacity ios already there

	// Allocate new(larger) memory
	new_items_container = new T[new_capacity];

	// Copy the items over from old array to new
	for (size_t i{ 0 }; i < m_size; ++i)
		new_items_container[i] = m_items[i];

	// Release old array
	delete[] m_items;

	// Make the current box wrap around the new array
	m_items = new_items_container;

	// Use the new capacity
	m_capacity = new_capacity;
}

template <typename T, size_t maximum>
void BoxContainer<T, maximum>::add(const T& item)
{
	if(m_size == maximum)
	{
		std::cout << "Maximum capacity reached. Not adding item" << std::endl;
		return;
	}

	if (m_size == m_capacity)
		expand(m_size + EXPAND_STEPS);

	m_items[m_size] = item;
	++m_size;
}

template <typename T, size_t maximum>
bool BoxContainer<T, maximum>::remove_item(const T& item)
{
	// Find the target item
	size_t index{ INT32_MAX }; // A large value outside the range of the current array

	for (size_t i{ 0 }; i < m_size; ++i)
	{
		if (m_items[i] == item)
		{
			index = i;
			break; // No need for the loop to go on
		}
	}

	if (index > m_size)
		return false; // Item not found in our box

	// If we fall here, the item is located at m_items[index]

	// We can either overshadow item at index with last element or move whole array to the left

	// 1. Overshadow item at index with last element decrement m_size
	m_items[index] = m_items[m_size - 1];

	// 2. Move array to the left
	for (size_t i{ index }; i < m_size - 1; ++i)
		m_items[i] = m_items[i + 1];

	// Decrement m_size
	m_size--;

	return true;
}

// Removing all is just removing one item, several times, until
// none is left, keeping track of the removed items
template <typename T, size_t maximum>
size_t BoxContainer<T, maximum>::remove_all(const T& item)
{
	size_t remove_count{};

	bool removed{ remove_item(item) };
	if (removed)
		++remove_count;

	while (removed)
	{
		removed = remove_item(item);
		if (removed)
			++remove_count;
	}

	return remove_count;
}


template <typename T, size_t maximum>
void BoxContainer<T, maximum>::operator+=(const BoxContainer& operand)
{
	// Make sure the current box can accomodate for the added new elements
	if (m_size + operand.size() > m_capacity)
		expand(m_size + operand.size());

	// Copy over elements
	for (size_t i{}; i < operand.m_size; ++i)
		m_items[m_size + i] = operand.m_items[i];

	m_size += operand.m_size;
}

template <typename T, size_t maximum>
BoxContainer<T, maximum> operator+(const BoxContainer<T, maximum>& left, const BoxContainer<T, maximum>& right)
{
	BoxContainer<T, maximum> result(left.size() + right.size());
	result += left;
	result += right;
	return result;
}

template <typename T, size_t maximum>
void BoxContainer<T, maximum>::operator=(const BoxContainer& source)
{
	T* new_items;

	// Check for self-assignment
	if (this == &source)
		return;

	// If the capacities are different, set up new internal array
	// that matches source, because we want object are assignment to
	// match source as much as possible
	if (m_capacity != source.m_capacity)
	{
		new_items = new T[source.m_capacity];
		delete[] m_items;
		m_items = new_items;
		m_capacity = source.m_capacity;
	}

	// Copy items over from source
	for (size_t i{ 0 }; i < source.size(); ++i)
		m_items[i] = source.m_items[i];

	m_size = source.m_size;
}







