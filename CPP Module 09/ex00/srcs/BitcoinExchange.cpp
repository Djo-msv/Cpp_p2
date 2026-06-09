#include "BitcoinExchange.hpp"

bool operator<(const date_s& a, const date_s& b)
{
    if (a.year != b.year)
	    return a.year > b.year;
    if (a.month != b.month)
	    return a.month > b.month;
    return a.day > b.day;
}

std::ostream& operator<<(std::ostream& os, const date_s& value) {
	os << (int)value.year << "-";
	if (value.month <= 9)
		os << '0';
	os << (int)value.month << "-";
	if (value.day <= 9)
		os << '0';
	os << (int)value.day;
	return (os);
}

bool	isNumber(std::string value, bool isFloat)
{
	int	commaCount = 0;

	if (value.empty())
		throw (std::runtime_error("No value provided."));
	for (std::string::iterator it = value.begin(); it != value.end(); it++) {
		if (!isdigit(*it)) {
			if (*it == '.' && isFloat && commaCount == 0)
				commaCount++;
			else
				return (false);
		}
	}
	return (true);
}

void	parseLinePrimaryDb(std::string line, date_s *date, double *exchange)
{
	int		year;
	int		month;
	int		day;
	int		negate;
	std::string	value;

	(line[0] == '-')? (line.erase(0, 1), negate = -1) : negate = 1;
	value = std::string(line, 0, line.find("-"));
	line.erase(0, line.find("-") + 1);
	if (!isNumber(value, false))
		throw (std::runtime_error("The database have to use digit for years!"));
	year = atoi(value.c_str()) * negate;
	if (year > INT16_MAX || year < INT16_MIN)
		throw (std::runtime_error("The database cannot include years outside of -32,768 and 32,767!"));

	value = std::string(line, 0, line.find("-"));
	line.erase(0, line.find("-") + 1);
	if (!isNumber(value, false))
		throw (std::runtime_error("The database have to use digit for months!"));
	month = atoi(value.c_str());
	if (month < 1 || month > 12)
		throw (std::runtime_error("month is not valid"));

	value = std::string(line, 0, line.find(","));
	line.erase(0, line.find(",") + 1);
	if (!isNumber(value, false))
		throw (std::runtime_error("The database have to use digit for days!"));
	day = atoi(value.c_str());
	if (day > 31 || day < 1)
		throw (std::runtime_error("day is not valid"));

	if (!isNumber(value, true))
		throw (std::runtime_error("The database have to use digit for exchange value!"));
	
	date->year = year;
	date->month = month;
	date->day = day;
	*exchange = atof(line.c_str());
}

void	checkDate(const date_s *date)
{
	if (date->day > 30 && (date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11))
		throw (std::runtime_error("day is not valid"));

	if (date->month == 2)
	{
		bool leap = date->year % 100 == 0 ? date->year % 400 : date->year % 4;
		if ((leap && date->day > 28) || (!leap && date->day > 29))
			throw (std::runtime_error("day is not valid"));
	}
}

void	setupPrimaryDb(std::map<date_s, double> *primaryDb)
{
	date_s		date;
	double		exchange;
	std::string	line;
	std::ifstream	file("data.csv");

	if (file.fail())
		throw std::runtime_error("File data.csv not found or can't be open!\nPlease check permition.");
	size_t count = 0;
	while (std::getline(file, line)) {
		try {
			parseLinePrimaryDb(line, &date, &exchange);
			checkDate(&date);
		}
		catch (const std::exception& e) {
			if (VERBOSE == 1)
				std::cout << "error at line : " << count << " /" << line << std::endl << e.what() << std::endl;
			count++;
			continue ;
		}
		primaryDb->insert(std::pair<const date_s, double>(date, exchange));
		count++;
	}
}

void	parseLineSecondDb(std::string line, date_s *date, double *value)
{
	int		year;
	int		month;
	int		day;
	int		negate;
	std::string	str;
	
	if (line.empty())
		throw (std::runtime_error("No value provided."));
	(line[0] == '-')? (line.erase(0, 1), negate = -1) : negate = 1;
	str = std::string(line, 0, line.find("-"));
	line.erase(0, line.find("-") + 1);
	if (!isNumber(str, false))
		throw (std::runtime_error("The database have to use digit for years!"));
	year = atoi(str.c_str()) * negate;
	if (year > INT16_MAX || year < INT16_MIN)
		throw (std::runtime_error("The database cannot include years outside of -32,768 and 32,767!"));

	str = std::string(line, 0, line.find("-"));
	line.erase(0, line.find("-") + 1);
	if (!isNumber(str, false))
		throw (std::runtime_error("The database have to use digit for months!"));
	month = atoi(str.c_str());
	if (month < 1 || month > 12)
		throw (std::runtime_error("month is not valid"));

	str = std::string(line, 0, line.find(" | "));
	line.erase(0, line.find(" | ") + 3);
	if (!isNumber(str, false))
		throw (std::runtime_error("The database have to use digit for days!"));
	day = atoi(str.c_str());
	if (day > 31 || day < 1)
		throw (std::runtime_error("day is not valid."));

	if (line.empty())
		throw (std::runtime_error("No value provided."));
	if (line[0] == '-')
		throw (std::runtime_error("Not a positive number."));
	if (!isNumber(line, true))
		throw (std::runtime_error("The database have to use digit for exchange value!"));
	if (atof(line.c_str()) > 1000)
		throw (std::runtime_error("The exchange value cannot exceed 1000"));
	
	date->year = year;
	date->month = month;
	date->day = day;
	*value = atof(line.c_str());
}

void	manageSecondDb(std::map<date_s, double> *primaryDb, const char *path)
{
	date_s		key;
	double		value = 0;
	std::string	line;
	std::ifstream	file(path);


	if (file.fail())
		throw std::runtime_error(std::string("File ") + path + " not found or can't be open!\nPlease check permition.");
	while (std::getline(file, line)) {
		try {
			parseLineSecondDb(line, &key, &value);
			checkDate(&key);
		}
		catch (const std::exception& e) {
			std::cout << "error : " << e.what() << std::endl;
			continue ;
		}
		std::map<date_s, double>::iterator mypair = primaryDb->lower_bound(key);
		if (mypair == primaryDb->end()) {
			std::cout << "error: the database has no date corresponding to " << key << '.' << std::endl;
			continue ;
		}
		std::cout << key << " => " << value << " = " << mypair->second * value << std::endl;
	}
}


