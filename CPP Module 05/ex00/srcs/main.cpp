#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat	val("Phal", 107);
			std::cout << val << std::endl;
			for (int i = 0; i != 1000; i++)
				val.incrementGrade();
			std::cout << val << std::endl;
			for (int i = 0; i != 80; i++)
				val.decrementGrade();
			std::cout << val << std::endl;
			std::cout << "end of try" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "fail" << std::endl;
			return (1);
		}
		return (0);
	}
	{
		try
		{
			Bureaucrat	val("Phil", 107);
			std::cout << val << std::endl;
			for (int i = 0; i != 30; i++)
				val.incrementGrade();
			std::cout << val << std::endl;
			for (int i = 0; i != 70; i++)
				val.decrementGrade();
			std::cout << val << std::endl;
			std::cout << "end of try" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "fail" << std::endl;
			return (1);
		}
		return (0);
	}
	{
		try
		{
			Bureaucrat	val("Phol", 107);
			std::cout << val << std::endl;
			for (int i = 0; i != 30; i++)
				val.incrementGrade();
			std::cout << val << std::endl;
			for (int i = 0; i != 80; i++)
				val.decrementGrade();
			std::cout << val << std::endl;
			std::cout << "end of try" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "fail" << std::endl;
			return (1);
		}
		return (0);
	}
}
