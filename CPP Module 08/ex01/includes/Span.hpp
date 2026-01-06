#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <climits>

class Span
{
	public :
		Span(int N);
		~Span();

		void addNumber(int value);

		int	shortestSpan();
		int	longestSpan();

	private :
		std::vector<int> _v;
		int	_size;
};
