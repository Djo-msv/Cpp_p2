#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	val("Phil", 107);
		for (int i = 0; i != 30; i++)
		{
			val.incrementGrade();
		}
		std::cout << "end of try" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "fail" << std::endl;
	}
	return (0);
}
