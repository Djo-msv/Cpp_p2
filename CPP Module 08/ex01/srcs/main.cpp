#include "Span.hpp"

int	main(void)
{
	Span	array(15);

	array.addNumber(0);
	array.addNumber(8);
	array.addNumber(5);
	array.addNumber(2);
	array.addNumber(1);
	array.addNumber(4);
	array.addNumber(7);

	std::cout << array.shortestSpan() << std::endl;
	std::cout << array.longestSpan() << std::endl;

	return (0);
}
