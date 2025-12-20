#pragma once

#include <iostream>
#include <stdint.h>

class Form;

class Bureaucrat
{
	public :
		Bureaucrat();
		Bureaucrat(const std::string &name, uint8_t grad);
		~Bureaucrat();

		std::string getName() const;
		uint8_t getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(Form value);

	private :
		const std::string	_name;
		uint8_t				_grade;

		class GradeTooHighException : public std::exception 
		{};
		class GradeTooLowException : public std::exception
		{};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& value);
