#include "printConvert.hpp"

void	print_char(char value)
{
	if (value > 30 && value < 127)
		std::cout << "char: " << value << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	print_int(int value)
{
	std::cout << "int: " << value << std::endl;
}

void	print_float(float value)
{
	std::cout << "float: " << value;
	if (value == floor(value) && isinf(value) == 0)
		std::cout << ".0";
	std::cout << 'f' << std::endl;
}

void	print_double(double value)
{
	std::cout << "double: " << value;
	if (value == floor(value))
		std::cout << ".0";
	std::cout << std::endl;
}

void	print_nan(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	print_inf(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

void	print_neginf(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void	print_exeption(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	print_error(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
