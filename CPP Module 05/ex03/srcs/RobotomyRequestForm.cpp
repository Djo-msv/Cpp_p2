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
	if (getSign() == 0 || value.getGrade() > getGradeToExecute())
		return ;

	std::cout << "Makes some drilling noises" << std::endl;
	sleep(1);

	srand(time(NULL));
	bool	randomValue = rand() % 2;
	if (randomValue)
		std::cout << value.getName() << " has been robotomized" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &value)
{
	(void)value;
	return *this;
}

