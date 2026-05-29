#pragma once

#include <cstdlib>
#include <time.h>
#include <unistd.h>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &value);
		RobotomyRequestForm(const std::string &name);
		virtual ~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const;

		RobotomyRequestForm &operator=(const RobotomyRequestForm &value);
};
