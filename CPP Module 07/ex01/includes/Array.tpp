#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _array(new T[0]), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{}

template <typename T>
Array<T>::Array(const Array &value) : Array(value.size())
{
	for (unsigned int i = 0; i != value.size(); i++)
		_array[i] = value[i];
}

template <typename T>
Array<T>::~Array()
{
	delete []_array;
}

template <typename T>
unsigned int	Array<T>::size(void)
{
	return (_size);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw(std::out_of_range("out of bounds"));
	else
		return (_array[i]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw(std::out_of_range("out of bounds"));
	else
		return (_array[i]);
}
