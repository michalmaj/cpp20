#pragma once

#include "stream_insertable.h"

class BoxContainer : public StreamInsertable
{
	//typedef int value_type; // Allows us to change what's stored in our container
	//						// Can make it store int, double, ...
	// Better version
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

private:
	value_type* m_items;
	size_t m_capacity;
	size_t m_size;

	void expand(size_t new_capacity);
};

