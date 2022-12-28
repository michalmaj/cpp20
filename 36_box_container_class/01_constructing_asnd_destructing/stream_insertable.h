#pragma once

#include <iostream>

class StreamInsertable
{
	friend std::ostream& operator<<(std::ostream& out, const StreamInsertable& operand);

public:
	virtual void stream_insert(std::ostream& out) const = 0;
	virtual ~StreamInsertable() = default;
};


