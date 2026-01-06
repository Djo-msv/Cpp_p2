#pragma once

#include <iostream>

template <typename T> int &easyfind(T *containers, int integer)
{
	for (size_t i = 0; i != containers->size(); i++)
	{
		if ((*containers)[i] == integer)
			return ((*containers)[i]);
	}
	throw (std::exception());
}
