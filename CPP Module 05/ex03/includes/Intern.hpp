#pragma once

#include "AForm.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public :
		Intern();
		Intern(const Intern &value);
		~Intern();

		AForm *makeForm(const std::string &name, const std::string &target);
};
