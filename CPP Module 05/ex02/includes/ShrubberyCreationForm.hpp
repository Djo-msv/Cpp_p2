#pragma once

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShruvveryCreationForm &value);
		~ShrubberyCreationForm();
		
		virtual void execution(Bureaucrat const &executor);
};

ShrubberyCreationForm operator=(const ShrubberyCreationForm &value);
