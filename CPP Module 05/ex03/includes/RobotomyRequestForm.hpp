#pragma once

#include <cstdlib>
#include <time.h>
#include <unistd.h>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &name);
		RobotomyRequestForm(const RobotomyRequestForm &value);
		virtual ~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const;

		RobotomyRequestForm &operator=(const RobotomyRequestForm &value);
};
