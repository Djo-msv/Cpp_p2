#include "PresidentialPardonForm.hpp"

PresidentialPardonForm() : AForm("default", 145, 137)
{}

PresidentialPardonForm(const std::string &name) : AForm(name, 145, 137)
{}

PresidentialPardonForm(const PresidentialPardonForm &value) : AForm(value)
{}

~PresidentialPardonForm()
{}

PresidentialPardonForm& operator=(const PreidentialPardonForm &value)
{
	(void)value;
	return (*this);
}
