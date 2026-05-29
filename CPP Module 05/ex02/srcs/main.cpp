#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"



int	main(void)
{
	Bureaucrat	chr1("Paul", 100);	

	PresidentialPardonForm Home("Home");
	RobotomyRequestForm Been("Been");
	ShrubberyCreationForm RoseBerry("RoseBerry");

	chr1.signForm(Home);
	chr1.signForm(Been);
	chr1.signForm(RoseBerry);

	chr1.executeForm(Home);
	chr1.executeForm(Been);
	chr1.executeForm(RoseBerry);

	return (0);
}
