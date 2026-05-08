#include "PmergeMe.hpp"

void	Object::swap(void)
{
	Object *tmp = pair.first;
	pair.first = pair.second;
	pair.second = tmp;
	size_t	tmp2 = x;
	x = y;
	y = tmp2;
}

void	sortPair(std::vector<Object*> *S)
{
	for (size_t i = 0; (*S)[i]; i++) {
		if ((*S)[i]->x < (*S)[i]->y)
			(*S)[i]->swap();
	}
}

void	insert(std::vector<Object*> *S, Object *value, size_t i)
{
	size_t	begin = 0;
	size_t	end = i + 1;
	size_t	mid;
	std::vector<Object*>::iterator it = S->begin();

	while (true) {
		mid = (end - begin) / 2 + begin;
		if (value->x > (*S)[mid]->x)
			begin = mid;
		else if (value->x < (*S)[mid]->x)
			end = begin;
		if (begin == end) {
			S->insert(it + mid, value);
			break;
		}
	}
}

void	createFordJohnsonSuite(std::vector<Object*> *S, std::vector<Object *> *s)
{
	size_t	i = 0; // perv size
	size_t	j = 0; // actual size
	size_t	k = 0; // total size

	S->clear();
	for (size_t iterator = 1; k < s->size(); iterator++) {
		j = pow(2, iterator) - i;
		if (j >= s->size())
			j = s->size();
		i = j;
		
		for (; j != 0; j--) // decrement j until 0
			insert(s, (*s)[j + k]->pair.second, j + k);
		k += i;
	}
	for (std::vector<Object*>::iterator it = s->begin(); it != s->end(); it++)
		S->push_back(*it);
}

void	pMergeMe(std::vector<Object*> *S)
{
	std::vector<Object *>	s;

	size_t i = 0;
	size_t j = 0;

	// put an alfe inside x, and other alfe inside y, if 1 remain, put inside y
	for (; (*S)[i]; i++) {
		if (i % 2) {
			Object *tmp = new Object;
			tmp->x = (*S)[i]->x;
			s.push_back(tmp);
		}
		else
		{
			s[j]->pair.second = (*S)[i];
			s[j++]->y = (*S)[i]->y;
		}
	}
	
	// sort pair to make x > y;
	sortPair(&s);

	// recurisivity. so x is sorted
	if (s.size() > 1)
		pMergeMe(&s);

	// insertion of y inside x, and put result insde S
	createFordJohnsonSuite(S, &s);
	for (std::vector<Object*>::iterator it = s.begin(); it != s.end(); it++)
		delete *it;

}

void	pMergeMeSetup(std::vector<long long> *S)
{
	std::vector<Object *>	s;

	// convert S to s
	

	for (size_t i = 0; (*S)[i]; i++) {
		Object *tmp = new Object;
		tmp->x = (*S)[i];
		s.push_back(tmp);
	}

	// sorte s with Merge-insertion sort
	pMergeMe(&s);

	// convert s to S
	for (size_t j = 0; s[j]; j++)
		(*S)[j] = s[j]->x;

	for (std::vector<Object*>::iterator it = s.begin(); it != s.end(); it++)
		delete *it;
}
