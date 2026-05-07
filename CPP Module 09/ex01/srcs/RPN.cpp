#include "RPN.hpp"

bool	iscalcule(char chr)
{
	return ((chr == '+' || chr == '-' || chr == '*' || chr == '/')? true : false);
}

void	calculeLastArgs(std::stack<double> *stack, char chr)
{
	double	x;
	double	y;

	if (stack->size() < 2)
		throw std::invalid_argument("Bad expression.");
	
	x = stack->top();
	stack->pop();
	y = stack->top();
	stack->pop();

	if (chr == '+')
		stack->push(y + x);
	if (chr == '-')
		stack->push(y - x);
	if (chr == '*')
		stack->push(y * x);
	if (chr == '/')
		stack->push(y / x);
}

double	invertedPolishmathematicalExpression(std::stack<double> *stack, std::string line)
{
	for (std::string::iterator it = line.begin(); it != line.end(); it++) {
		if (isdigit(*it))
			stack->push(*it - '0');
		else if (iscalcule(*it))
			calculeLastArgs(stack, *it);
		else if (*it == ' ')
			continue ;
		else
			throw std::invalid_argument(std::string("Invalide arguments / ") + std::string(1, *it) + '.');
	}
	if (stack->size() != 1)
		throw std::invalid_argument("Bad expression.");
	return (stack->top());
}
