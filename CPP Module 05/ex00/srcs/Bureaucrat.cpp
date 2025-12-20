#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{}

Bureaucrat::Bureaucrat(const std::string &name, uint8_t grade) : _name(name)
{
	_grade = 150;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade <= 0)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat(void)
{}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

uint8_t	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowException(); 
	_grade++;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade <= 0)
		throw GradeTooHighException();
	_grade--;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt)
{
    os << dt.getName() << ", bureaucrat grade" << dt.getGrade() << '.' << std::endl;
    return os;
}
