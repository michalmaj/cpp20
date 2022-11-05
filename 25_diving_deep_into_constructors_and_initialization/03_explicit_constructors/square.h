#pragma once
class Square
{
public:
	explicit  Square(double side_param);
	~Square() = default;
	double surface() const;

private:
	double m_side;
};

