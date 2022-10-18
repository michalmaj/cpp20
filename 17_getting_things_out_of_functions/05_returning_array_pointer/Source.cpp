#include <iostream>
#include <tuple>
#include <typeinfo>

// Because our passed to function array is const, in this case our function
// also must be marked as a const
std::tuple<const double*, double, size_t> find_max_index(const double scores[], size_t count);

int main()
{
	double array[]{ 1.0,2.0,3.0,45.0,5.0,6.0,7.0,8.0,79.0,10.0 };
	auto [max_val, max_val1, idx] = find_max_index(array, std::size(array));

	std::cout << "max value directly from array: " << *max_val << ", type: "
		<< typeid(max_val).name() << std::endl;
	std::cout << "max value indirectly from array: " << max_val1 << ", type: "
		<< typeid(max_val1).name() << std::endl;
	std::cout << "index of max element: " << idx << ", type: "
		<< typeid(idx).name() << std::endl;

	return 0;
}


/**
 * \brief Function to find max value inside array.
 * \param scores Given array of values.
 * \param count Size of the array.
 * \return Max value from the array, max value and index of max value.
 */
std::tuple<const double*, double, size_t> find_max_index(const double scores[], size_t count)
{
	size_t max_index{};
	double max{};

	for(size_t i{0}; i < count; ++i)
	{
		if(scores[i] > max)
		{
			max = scores[i];
			max_index = i;
		}
	}
	return std::make_tuple(&scores[max_index], max, max_index);
}

