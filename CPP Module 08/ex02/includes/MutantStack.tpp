#pragma once

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
{}

MutantStack(const MutantStack &value)
{
	*this = value;
}

~MutantStack(void)
{}

iterator begin()
{
	return (this->c.begin());
}

iterator end()
{
	return (this->c.end());
}
