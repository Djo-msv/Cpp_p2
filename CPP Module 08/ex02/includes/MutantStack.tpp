#pragma once

#include "MutantStack.hpp"

#include <iostream>
#include <stack>


template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>() 
{}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &value) : std::stack<T, Container>(value)
{}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{}

