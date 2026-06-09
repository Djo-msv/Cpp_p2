#include "PmergeMe.hpp"
#include <string>

int	main(int argc, char **argv)
{
	std::vector<long long>	S;

	if (argc < 2) {
		std::cout << argv[0] << " need an list." << std::endl;
		return (1);
	}

	std::string str;
	for (int i = 1; i != argc; i++) {
		str += std::string(argv[i]);
		str += std::string(" ");
	}

	std::string::iterator it = str.begin();
	while (true) {
		if (it != str.end() && isdigit(*it))	
		S.push_back(atol(std::string(str, it - str.begin()).c_str()));
		while (it != str.end() && isdigit(*it))
			it++;
		if (it == str.end())
			break ;
		if (*it == ' ')
			it++;
		else
			return (1);
	}
	pMergeMeSetup(&S);
	for (std::vector<long long>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}
