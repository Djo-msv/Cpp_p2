#pragma once

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &value);
		~PresidentialPardonForm();

		virtual void execution(Bureaucrat const &executor);
};

PresidentialPardonForm &operator=(const PresidentialPardonForm &value);
