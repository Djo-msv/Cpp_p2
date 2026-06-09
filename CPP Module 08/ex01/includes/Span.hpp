#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <climits>
#include <algorithm>

class Span
{
	public :
		Span(int N);
		Span(const Span &value);
		~Span();

		void addNumber(int value);
		void addMultipleNumber(int *value, size_t n);

		int	shortestSpan();
		int	longestSpan();

		Span &operator=(const Span &value);

	private :
		std::vector<int> _v;
		int	_size;
};
