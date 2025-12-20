#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Form	For("Exam", 70, 70);
		Bureaucrat	val("Phil", 107);
	
		val.signForm(For);
		for (int i = 0; i != 60; i++)
		{
			val.decrementGrade();
		}
		val.signForm(For);
		std::cout << "end of try" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "fail" << std::endl;
	}
	return (0);
}
