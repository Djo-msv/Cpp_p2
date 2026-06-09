#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdexcept>

template <typename T> class Array 
{
	public :
		Array();
		Array(const unsigned int n);
		Array(const Array &value);
		~Array();

		unsigned int size() const;

		T& operator[](unsigned int);
		const T& operator[](unsigned int) const;

	private :
		T *_array;
		unsigned int _size;
};

#include "Array.tpp"
