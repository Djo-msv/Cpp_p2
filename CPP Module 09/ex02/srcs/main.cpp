#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	std::vector<long long>	S;

	if (argc < 2) {
		std::cout << argv[0] << " need an list." << std::endl;
		return (1);
	}
	else if (argc > 2) {
		std::cout << argv[0] << " need an unique list." << std::endl;
		return (1);
	}
	std::string				str(argv[1]);

	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		if (isdigit(*it))
			S.push_back(atol(std::string(1, *it).c_str()));
		else if (*it != ' ') {
			return (1);
		}
	}
	pMergeMeSetup(&S);
}
