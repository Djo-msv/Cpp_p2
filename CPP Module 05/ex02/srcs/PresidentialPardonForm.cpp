#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name) : AForm(name, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &value) : AForm(value)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(const Bureaucrat &value) const
{
	if (getSign() == 0 || value.getGrade() > getGradeToExecute())
		return ;

	std::cout << "Informs that " << value.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &value)
{
	(void)value;
	return (*this);
}
