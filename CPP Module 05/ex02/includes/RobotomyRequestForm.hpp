#pragma once

class RobotomyRequestForm : public AForm
{
	public :
		RobotmyRequestForm();
		RobotomyRequestFor(const RobotomyRequestForm &value);
		~RobotmyRequestForm();

		virtual void execution(Bureaucrat const &executor);

		RobotomyRequestFor operator=(const RobotomyRequestFor &value);
};
