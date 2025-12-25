#include "Intern.hpp"

Intern::Intern(void)
{}

Intern::Intern(const Intern &value)
{
	(void)value;
}

Intern::~Intern()
{}

AForm	*callShrubberyCreationFormConstructor(std::string target)
{
	AForm *val = new ShrubberyCreationForm(target) ;
	return (val);
}

AForm	*callRobotomyRequestFormConstructor(std::string target)
{
	AForm *val = new RobotomyRequestForm(target);
	return (val);
}

AForm	*callPresidentialPardonFormConstructor(std::string target)
{
	AForm *val = new PresidentialPardonForm(target);
	return (val);
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string	Form[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm*    (*_ptr[3])(std::string) = {&callShrubberyCreationFormConstructor, &callRobotomyRequestFormConstructor, &callPresidentialPardonFormConstructor};

	int i;

	for (i = 0; i != 3 && name != Form[i]; i++)
		continue ;
	return (i == 3 ? NULL : _ptr[i](target));
}
