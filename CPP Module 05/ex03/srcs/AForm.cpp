#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{}

AForm::AForm(const std::string &name, const uint8_t &gradeToSign, const uint8_t &gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign <= 0 || gradeToExecute <= 0)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &value) : _name(value.getName()), _gradeToSign(value.getGradeToSign()), _gradeToExecute(value.getGradeToSign())
{}

AForm::~AForm(void)
{}

std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getSign(void) const
{
	return (_isSigned);
}

uint8_t AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

uint8_t AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat value)
{
	if (value.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm &value)
{
	(void) value;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& value)
{
    os << "Form name : " << value.getName() << std::endl << "Is signed : " << value.getSign() << std::endl << "Grade required to sign it : " << (int)value.getGradeToSign() << std::endl << "Grade required to execute it : " << (int)value.getGradeToExecute() << std::endl;
	return os;
}
