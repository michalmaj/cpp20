#pragma once

#include "stream_insertable.h"

class BoxContainer  : public StreamInsertable
{
	//typedef int value_type; // Allows us to change what's stored in our container
	//						// Can make it store int, double, ...
	// Better version
	using value_type = int;

	static constexpr size_t DEFAULT_CAPACITY{ 30 };

public:
	BoxContainer(size_t capacity = DEFAULT_CAPACITY);
	BoxContainer(const BoxContainer& source);
	virtual ~BoxContainer();

	// StreamInsertable Interface
	virtual void stream_insert(std::ostream& out) const override;

	// Helper getters methods
	size_t size() const { return m_size; }
	size_t capacity() const { return m_capacity; }

	// Placeholder to play around with the class
	void dummy_initialize()
	{
		// Put 10 items
		for(size_t i{0}; i < 10; ++i)
		{
			m_items[i] = i + 12;
			m_size++;
		}
	}

private:
	value_type* m_items;
	size_t m_capacity;
	size_t m_size;
};

