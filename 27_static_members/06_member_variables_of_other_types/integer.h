#pragma once


class Integer
{
public:
	explicit Integer(int value);
	Integer() = default;
	~Integer();

	int get_value() const {
		return inner_int;
	}

	void set_value(int new_val) {
		inner_int = new_val;
	}

private:
	int inner_int{ 0 };
};

