#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("defaut", 25, 5)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) : AForm(name, 25, 5)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &value) : AForm(value)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

void	printAsciiTree(const std::string &fileName)
{
	std::ofstream outfile (fileName.c_str());

	outfile << "        _-_" << std::endl;
	outfile << "     /~~   ~~\\" << std::endl;
	outfile << "   /~~      ~~\\" << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~" << std::endl;
	outfile << "_- -   | | _- _" << std::endl;
	outfile << "  _ -  | |   -_" << std::endl;
	outfile << "      // \\\\" << std::endl;

	outfile.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat &value) const
{
	if (getSign() == 0 || value.getGrade() > getGradeToExecute())
		return ;

	printAsciiTree(value.getName() + "_shrubbery");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &value)
{
	(void)value;
	return (*this);
}
