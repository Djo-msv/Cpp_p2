#pragma once

# include "Bureaucrat.hpp"

class AForm
{
	public :
		AForm();
		AForm(const std::string &name, const uint8_t &gradeToSign, const uint8_t &gradeToExecute);
		AForm(const AForm &value);
		virtual ~AForm();

		std::string getName() const;
		bool getSign() const;
		uint8_t getGradeToSign() const;
		uint8_t getGradeToExecute() const;
		
		void beSigned(Bureaucrat value);
		virtual void execute(Bureaucrat const & executor) const = 0;

		AForm& operator=(const AForm &value);
	
	private :
		std::string	_name;
		bool 				_isSigned;
		const uint8_t		_gradeToSign;
		const uint8_t		_gradeToExecute;

		class GradeTooHighException : public std::exception 
		{};
		class GradeTooLowException : public std::exception
		{};
};

std::ostream& operator<<(std::ostream& os, const AForm& value);
