#include "Span.hpp"

Span::Span(int N) : _size(N)
{}

Span::Span(const Span &value) : _v(value._v), _size(value._size)
{}

Span::~Span()
{}

void	Span::addNumber(int value)
{
	if (static_cast<int>(_v.size()) < _size)
		_v.push_back(value);
	else
		throw (std::exception());
}

void	Span::addMultipleNumber(int *value, size_t n)
{
	size_t i = 0;

	if (n < 0)
		throw (std::exception());
	while (i != n)
		_v.push_back(value[i++]);
}

int	Span::shortestSpan(void)
{
	int	Span = INT_MAX;
	class Span	sorted(*this);

	sort(sorted._v.begin(), sorted._v.end());
	for (int i = 0; i + 1 != static_cast<int>(sorted._v.size()); i++)
	{
		if (sorted._v[i + 1] - sorted._v[i] < Span)
			Span = sorted._v[i + 1] - sorted._v[i];
	}
	return (Span);
}

int Span::longestSpan(void)
{
	Span	sorted(*this);

	sort(sorted._v.begin(), sorted._v.end());
	return (sorted._v[sorted._v.size() - 1] - sorted._v[0]);
}
