#include "Span.hpp"

Span::Span(int N) : _size(N)
{}

Span::~Span()
{}

void	Span::addNumber(int value)
{
	std::vector<int>::iterator it;

	if (static_cast<int>(_v.size()) < _size)
	{
		it = lower_bound(_v.begin(), _v.end(), value);
		_v.insert(it, value);
	}
	else
		throw (std::exception());
}

int	Span::shortestSpan(void)
{
	int	Span = INT_MAX;

	for (int i = 0; i + 1 != static_cast<int>(_v.size()); i++)
	{
		if (_v[i + 1] - _v[i] < Span)
			Span = _v[i + 1] - _v[i];
	}
	return (Span);
}

int Span::longestSpan(void)
{
	return (_v[_v.size() - 1] - _v[0]);
}
