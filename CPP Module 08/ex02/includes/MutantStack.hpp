#pragma once

#include <iostream>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public :
		typedef typename std::deque<T>::iterator iterator;

		MutantStack(void) : std::stack<T, Container>() {}
		virtual ~MutantStack(void) {}

		typename Container::iterator    begin(void) {
			return (this->c.begin());
		}

		typename Container::iterator    end(void) {
			return (this->c.end());
		}
};

