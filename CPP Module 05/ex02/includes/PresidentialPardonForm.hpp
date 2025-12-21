#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &name);
		PresidentialPardonForm(const PresidentialPardonForm &value);
		virtual ~PresidentialPardonForm();

		void execute(Bureaucrat const &executor) const;

		PresidentialPardonForm &operator=(const PresidentialPardonForm &value);
};
