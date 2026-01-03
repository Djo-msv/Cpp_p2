#include "ScalarConverter.hpp"
#include <iomanip>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	std::string	value(argv[1]);

	std::cout << std::setprecision (64);
	std::cout << "input value : " << value << std::endl;

	ScalarConverter::Convert(value);
	return (0);
}
