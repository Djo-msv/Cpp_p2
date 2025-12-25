#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern someRandomIntern;
	Bureaucrat B("Charles", 1);
	AForm* rrf = NULL;

	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	if (!rrf)
		return (-1);
	B.signForm(*rrf);
	rrf->execute(B);

	delete rrf;
}
