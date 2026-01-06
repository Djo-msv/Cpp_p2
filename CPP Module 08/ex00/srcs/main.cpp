#include "easyfind.hpp"

#include <vector>

int	main(void)
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(7);
	v.push_back(9);
	v.push_back(4);
	v.push_back(8);
	v.push_back(0);
	v.push_back(6);

	try
	{
		easyfind(&v, 4) = 0;
		std::cout << "found" << std::endl;
	}
	catch (std::exception)
	{
		std::cout << "failure" << std::endl;
	}

	try
	{
		easyfind(&v, 4) ;
		std::cout << "found" << std::endl;
	}
	catch (std::exception)
	{
		std::cout << "failure" << std::endl;
	}

	return (0);
}
