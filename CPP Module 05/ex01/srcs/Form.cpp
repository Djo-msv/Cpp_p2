#include "Form.hpp"

Form::Form(void) : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{}

Form::Form(const std::string &name, const uint8_t &gradeToSign, const uint8_t &gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign <= 0 || gradeToExecute <= 0)
		throw GradeTooHighException();
}

Form::~Form(void)
{}

std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getSign(void) const
{
	return (_isSigned);
}

uint8_t Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

uint8_t Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat value)
{
	if (value.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& value)
{
    os << "Form name : " << value.getName() << std::endl << "Is signed : " << value.getSign() << std::endl << "Grade required to sign it : " << (int)value.getGradeToSign() << std::endl << "Grade required to execute it : " << (int)value.getGradeToExecute() << std::endl;
	return os;
}
