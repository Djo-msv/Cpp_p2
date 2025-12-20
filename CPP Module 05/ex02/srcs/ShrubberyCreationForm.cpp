#include "ShrubberyCreationForm.hpp"

ShubberyCreationForm::ShubberyCreationForm(void) : AForm("defaut", 25, 5)
{}

ShubberyCreationForm::ShubberyCreationForm(const std::string &name) : AForm(name, 25, 5)
{}

ShubberyCreationForm::ShubberyCreationForm(const ShubberyCreationForm &value)
{}

ShubberyCreationForm::~ShubberyCreationForm(void)
{}

ShubberyCreationForm &operator=(const ShubberyCreationForm &value)
{
	(void)value;
	return ;
}
