#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"



int	main(void)
{
	Bureaucrat	chr1("Paul", 150);	

	PresidentialPardonForm Henry("Henry");

	chr1.signForm(Henry);

	chr1.executeForm(Henry);

	return (0);
}
