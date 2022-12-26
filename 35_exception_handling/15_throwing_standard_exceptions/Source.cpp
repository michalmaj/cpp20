#include <iostream>
#include <string_view>
#include <exception>
#include <format>

class Students
{
public:
	Students() = delete;
	Students(std::string_view s1, std::string_view s2, std::string_view s3,
		std::string_view s4, std::string_view s5)
	{
		m_students[0] = s1; m_students[1] = s2;
		m_students[2] = s3; m_students[3] = s4;
		m_students[4] = s5;
	}
	~Students() = default;

	std::string_view get_students(size_t index) const
	{
		const std::string message = std::format(
			"Index out of range, valid range [{},{}]", 0, 4);

		if (index < 0 or index >= 5)
			throw std::out_of_range(message);

		return m_students[index];
	}

private:
	std::string m_students[5];
};

int main()
{
	Students students{ "John Snow", "Brynden Tully", "Syrio Forel", "Arya Stark", "Arthur Dayne" };

	try
	{
		std::cout << students.get_students(2) << std::endl;
		std::cout << students.get_students(-2) << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception caught: " << ex.what() << std::endl;
	}

	return 0;
}