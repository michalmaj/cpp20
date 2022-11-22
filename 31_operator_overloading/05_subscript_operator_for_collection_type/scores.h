#pragma once

#include <iostream>
#include <string>

class Scores
{
public:
	Scores() = delete;
	Scores(const std::string& course_name_param, size_t N=20)
		: course_name(course_name_param), size(N)
	{
		m_scores = new double[size]{};
	}
	~Scores()
	{
		delete[] m_scores;
	}

	void print_info() const
	{
		for (size_t i{ 0 }; i < size; ++i)
			std::cout << m_scores[i] << " ";
		std::cout << std::endl;
	}

	double& operator[](size_t index);
	const double& operator[](size_t index) const;


private:
	std::string course_name;
	double* m_scores;
	size_t size;
};

