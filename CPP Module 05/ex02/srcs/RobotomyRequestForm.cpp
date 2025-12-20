#include "RobotomyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm(void) : AForm("default", 72, 45)
{}

RobotmyRequestForm::RobotmyRequestForm(const std::string &name) : AForm(name, 72, 45)
{}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm &value)
{}

RobotmyRequestForm::~RobotmyRequestForm()
{}

RobotmyRequestForm &operator=(const RobotmyRequestForm &value)
{
	(void)value;
	return *this;
}

