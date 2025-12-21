#pragma once

#include <iostream>
#include <fstream> 

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &name);
		ShrubberyCreationForm(const ShrubberyCreationForm &value);
		virtual ~ShrubberyCreationForm();
		
		void execute(Bureaucrat const &executor) const;

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &value);
};

