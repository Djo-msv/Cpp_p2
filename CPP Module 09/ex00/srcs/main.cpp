#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::map<date_s, double> primaryDb;

	if (argc != 2) {
		std::cout << argv[0] << " need database!" << std::endl;
		return (1);
	}
	try {
		setupPrimaryDb(&primaryDb);
		manageSecondDb(&primaryDb, argv[1]);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
