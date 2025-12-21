#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"



int	main(void)
{
	Bureaucrat	chr1("Paul", 1);	

	PresidentialPardonForm Henry("Henry");
	RobotomyRequestForm Claud("Claud");
	ShrubberyCreationForm Laurent ("Laurent");

	chr1.signForm(Henry);
	chr1.signForm(Claud);
	chr1.signForm(Laurent);

	chr1.executeForm(Henry);
	chr1.executeForm(Claud);
	chr1.executeForm(Laurent);

	return (0);
}
