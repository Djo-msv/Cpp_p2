#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T& containers, const int integer)
{
	typename T::const_iterator	it = std::find(containers.begin(), containers.end(), integer);
	if (it == containers.end())
		throw (std::exception());

	return it;
};

template <typename T>
typename T::iterator easyfind(T& containers, int integer)
{
	typename T::iterator	it = std::find(containers.begin(), containers.end(), integer);
	if (it == containers.end())
		throw (std::exception());

	return it;
};
