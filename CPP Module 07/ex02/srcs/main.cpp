#include "Array.hpp"

int	main(void)
{
	Array<int> intArray(15);

	for (unsigned int i = 0; i != intArray.size(); i++)
		intArray[i] = i;
	for (unsigned int i = 0; i != intArray.size(); i++)
		std::cout << i << ": " << intArray[i] << std::endl;

	try
	{
		intArray[15];
	}
	catch(std::exception)
	{
		std::cout << "fail" << std::endl;
	}
	return (1);
}
