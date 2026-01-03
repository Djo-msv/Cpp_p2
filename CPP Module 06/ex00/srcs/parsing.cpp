#include "parsing.hpp"
#include "ScalarConverter.hpp"

int	is_int(std::string &value)
{
	std::string::iterator it;

	if (value.length() == 0 || value.length() > 11 || atof(value.c_str()) > MAX_INT || atof(value.c_str()) < MIN_INT)
		return (0);
	for(it = value.begin(); it != value.end(); it++)
	{
		if (it == value.begin() && *it == '-')
			continue ;
		if (*it < '0' || *it > '9')
			return (0);
	}
	if (*(it - 1) >= '0' && *(it - 1) <= '9')
		return (1);
	return (0);
}

int is_char(std::string *value)
{
	if (value->length() == 1)
		return (1);
	if (value->length() == 3 && (*value)[0] == '\'' && (*value)[2] == '\'')
	{
		char	tmp = (*value)[1];
		value->clear();
		*value = &tmp;
		return (1);
	}
	return (0);
}

int	is_float(std::string &value)
{
	int	nb_comma = 0;

	for(std::string::iterator it = value.begin(); it != value.end(); it++)
	{
		if (it == value.begin() && *it == '-')
			continue ;
		if (it == value.end() - 1 && *it == 'f' && *(it - 1) >= '0' && *(it - 1) <= '9')
			return(1);
		if ((*it < '0' || *it > '9') && *it != '.')
			return(0);
		if (*it == '.')
			nb_comma++;
		if (nb_comma >= 2)
			return(0);
	}
	return (0);
}

int	is_double(std::string &value)
{
	int	nb_comma = 0;
	std::string::iterator it;

	if (value.length() == 0)
		return (0);
	for(it = value.begin(); it != value.end(); it++)
	{
		if (it == value.begin() && *it == '-')
			continue ;
		if ((*it < '0' || *it > '9') && *it != '.')
			return(0);
		if (*it == '.')
			nb_comma++;
		if (nb_comma >= 2)
			return(0);
	}
	if (*(it - 1) >= '0' && *(it - 1) <= '9')
		return (1);
	return (0);
}

int	is_exeption(std::string &value)
{
	if (value == "nan" || value == "nanf")
		return (1);
	return (0);
}
