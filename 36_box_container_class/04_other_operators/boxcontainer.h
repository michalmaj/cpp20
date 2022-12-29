#pragma once

#include "stream_insertable.h"

class BoxContainer : public StreamInsertable
{
	using value_type = int;

	static constexpr size_t DEFAULT_CAPACITY{ 30 };
	static constexpr size_t EXPAND_STEPS{ 5 }; // The box expands the capacity by this amount

public:
	BoxContainer(size_t capacity = DEFAULT_CAPACITY);
	BoxContainer(const BoxContainer& source);
	virtual ~BoxContainer();

	// StreamInsertable Interface
	virtual void stream_insert(std::ostream& out) const override;

	// Helper getters methods
	size_t size() const { return m_size; }
	size_t capacity() const { return m_capacity; }

	// Method to add items to the collection
	void add(const value_type& item);

	// Remove items
	bool remove_item(const value_type& item);
	size_t remove_all(const value_type& item);

	// In class operators
	void operator+=(const BoxContainer& operand);
	void operator=(const BoxContainer& source);

private:
	value_type* m_items;
	size_t m_capacity;
	size_t m_size;

	void expand(size_t new_capacity);
};


// Free operators
BoxContainer operator+(const BoxContainer& left, const BoxContainer& right);

