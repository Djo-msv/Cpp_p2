#include "ScalarConverter.hpp"

void	printInt(bool isPrintable, int nbDigit, const std::string &value)
{
	long	integer;

	integer = atol(value.c_str());
	if (isPrintable && (nbDigit > 11 || (integer > MAX_INT || integer < MIN_INT) || nbDigit == 0))
		isPrintable = 0;
	if (isPrintable)
		std::cout << "int: " << static_cast<int>(integer) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void	parsInt(const std::string &value)
{
	int	nbComma = 0;
	int	nbDigit = 0;
	std::string::const_iterator	it;

	for (it = value.begin(); it != value.end(); it++)
	{
		if ((static_cast<char>(*it) == '-' || static_cast<char>(*it) == '+') && it == value.begin())
			it++;
		else if (static_cast<char>(*it) == 'f')
		{
			it++;
			break ;
		}
		if (!std::isdigit(*it) && static_cast<char>(*it) != '.')
				break ;
		if (static_cast<char>(*it) == '.')
			nbComma++;
		if (nbComma > 1)
			break ;
		if (nbComma == 0)
			nbDigit++;
	}
	printInt(it == value.end() && static_cast<char>(*(--it)) != '.', nbDigit, value);
}

double	parsValue(const std::string &value)
{
	if (value.size() == 1)
		return (static_cast<double>(value[0]));
	if (value == "nan" || value == "nanf")
		return (static_cast<double>(nan("")));
	std::ostringstream oss;
	oss << atof(value.c_str());
	if (oss.str() == value || oss.str() == value + "f")
		return (atof(value.c_str()));
	return (0.0f);
}

void ScalarConverter::Convert(const std::string &value)
{
	double dValue = parsValue(value);

	std::cout << dValue << std::endl;
//	parsInt(value);
//	std::cout << "int    : " << atoi(charValue) << std::endl;
//	std::cout << "float  : " << static_cast<float>(atof(charValue)) << std::endl;
//	std::cout << "double : " << atof(charValue) << std::endl;
}
