#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("default", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name) : AForm(name, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &value) : AForm(value)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(const Bureaucrat &value) const
{
	(void)value;
	std::cout << "RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &value)
{
	(void)value;
	return *this;
}

