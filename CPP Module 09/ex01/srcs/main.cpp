#include "RPN.hpp"

int	main(int argc, char **argv)
{
	std::stack<double> stack;
	if (argc < 2) {
		std::cout << argv[0] << " need an inverted Polish mathematical expression." << std::endl;
		return (1);
	}
	else if (argc > 2) {
		std::cout << argv[0] << " need an unique Polish mathematical expression." << std::endl;
		return (1);
	}
	try {
		std::cout << invertedPolishmathematicalExpression(&stack, std::string(argv[1])) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
