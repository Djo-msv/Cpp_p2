#include "whatever.hpp"

int	main(void)
{
	int	a = 1;
	int	b = 6;

	double c = 5.3;
	double d = -3.6;

	std::string	e = "first string";
	std::string	f = "second string";

	std::cout << max(a, b) << std::endl;
	std::cout << max(c, d) << std::endl;

	std::cout << e << " | " << f << std::endl;
	swap(e, f);
	std::cout << e << " | " << f << std::endl;
	return (0);
}
