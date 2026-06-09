#include "Span.hpp"

int	main(void)
{
	int		tab[] = {9, 8, 7, 6, 5, 3, 1};
	Span	array(15);

	array.addNumber(0);

	array.addMultipleNumber(tab, 7);

	std::cout << array.shortestSpan() << std::endl;
	std::cout << array.longestSpan() << std::endl;

	

	return (0);
}
