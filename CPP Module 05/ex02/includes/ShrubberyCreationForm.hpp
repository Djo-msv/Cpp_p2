#pragma once

#include <iostream>
#include <fstream> 

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &value);
		ShrubberyCreationForm(const std::string &name);
		virtual ~ShrubberyCreationForm();
		
		void execute(Bureaucrat const &executor) const;

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &value);
};

