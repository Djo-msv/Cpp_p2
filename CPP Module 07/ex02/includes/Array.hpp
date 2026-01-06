#pragma once

#include <iostream>
#include <stdexcept>

template <typename T> class Array 
{
	public :
		Array();
		Array(unsigned int n);
		Array(const Array &value);
		~Array();

		unsigned int size();

		T& operator[](unsigned int);
		const T& operator[](unsigned int) const;

	private :
		T *_array;
		unsigned int _size;
};

#include "Array.tpp"
