#include "Form.hpp"

Bureaucrat::Bureaucrat(void)
{}

Bureaucrat::Bureaucrat(const Bureaucrat &value) : _name(value._name)
{
	_grade = value._grade;
}

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

void	Bureaucrat::signForm(Form &value)
{
	try
	{
		value.beSigned(*this);
		std::cout << *this << " signed " << value << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn’t sign " << value << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt)
{
    os << dt.getName() << ", bureaucrat grade" << dt.getGrade() << '.' << std::endl;
    return os;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &value)
{
	(void) value;
	return (*this);
}
