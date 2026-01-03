#include "ScalarConverter.hpp"
#include "printConvert.hpp"
#include "parsing.hpp"

void	convert_int(int value)
{
	if (value > 128 || value < 0)
		std::cout << "char: impossible" << std::endl;
	else
		print_char(static_cast<char>(value));
	print_int(value);
	print_float(static_cast<float>(value));
	print_double(static_cast<double>(value));
}

void	convert_char(char value)
{
	if (value < 0)
		std::cout << "char: impossible" << std::endl;
	else
		print_char(value);
	print_int(static_cast<int>(value));
	print_float(static_cast<float>(value));
	print_double(static_cast<double>(value));
}

void	convert_float(float value)
{
	if (value > 129 || value < 0)
		std::cout << "char: impossible" << std::endl;
	else
		print_char(static_cast<char>(value));
	if (value < (double)MAX_INT + 1 && value > MIN_INT)
		print_int(static_cast<int>(value));
	else
		std::cout << "int: impossible" << std::endl;
	print_int(static_cast<int>(value));
	print_float(value);
	print_double(static_cast<double>(value));
}

void	convert_double(double value)
{
	if (value > 129 || value < 0)
		std::cout << "char: impossible" << std::endl;
	else
		print_char(static_cast<char>(value));
	if (value < (double)MAX_INT + 1 && value > MIN_INT)
		print_int(static_cast<int>(value));
	else
		std::cout << "int: impossible" << std::endl;
	print_float(static_cast<float>(value));
	print_double(value);
}

void ScalarConverter::Convert(std::string &value)
{
	if (is_int(value))
		convert_int(atoi(value.c_str()));
	else if (is_char(&value))
		convert_char(value[0]);
	else if (is_float(value))
		convert_float(atof(value.c_str()));
	else if (is_double(value))
		convert_double(atof(value.c_str()));
	else if (is_exeption(value))
		print_exeption();
	else
		print_error();
}
