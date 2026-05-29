#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &value);
		PresidentialPardonForm(const std::string &name);
		virtual ~PresidentialPardonForm();

		void execute(Bureaucrat const &executor) const;

		PresidentialPardonForm &operator=(const PresidentialPardonForm &value);
};
