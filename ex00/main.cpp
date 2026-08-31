#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	int	arr[] = {1, 2, 3, 4, 5};
	size_t	arr_size = 5;

	const std::vector<int>	const_vec(arr, arr + arr_size);
	std::vector<int>		vec(arr, arr + arr_size);

	try
	{
		std::vector<int>::const_iterator const_it = easyfind(const_vec, 3);
		std::cout << "Found value in const_vec: " << *const_it << std::endl;

		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found value1: " << *it << std::endl;

		it = easyfind(vec, 6);
		std::cout << "Found value2: " << *it << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}