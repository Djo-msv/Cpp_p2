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
	for (std::vector<Object*>::iterator it = S->begin(); it != S->end(); it++) {
		if ((*it)->x < (*it)->y)
			(*it)->swap();
	}
}

void	insert(std::vector<Object*> *S, Object *value, size_t i)
{
	size_t	begin = 0;
	size_t	end = i;
	size_t	mid;
	std::vector<Object*>::iterator it = S->begin();

	while (begin <= end) {
		mid = (end - begin) / 2 + begin;
		if (begin == mid)
			break ;
		if(end == mid)
			break ;
		if ((*S)[mid]->x == value->x) {
			S->insert(it + mid, value);
			return ;
		}
		else 
			((*S)[mid]->x > value->x)? end = mid - 1: begin = mid + 1;
	}
	if ((*S)[mid]->x < value->x)
		S->insert(it + mid + 1, value);
	if ((*S)[mid]->x > value->x)
		S->insert(it + mid, value);

}

void	createFordJohnsonSuite(std::vector<Object*> *S, std::vector<Object *> *s)
{
	size_t	i = 0; // perv size
	size_t	j = 0; // actual size
	size_t	k = 0; // total size
	size_t	nby = s->size();

	S->clear();
	for (std::vector<Object*>::iterator it = s->begin(); it != s->end(); it++) {
		if ((*it)->isPair)
			S->push_back((*it)->pair.first);
	}
	for (size_t iterator = 1; k < nby; iterator++) {
		j = pow(2, iterator) - i;
		if (j + k >= nby)
			j = nby - k;
		i = j;
		
		for (; j != 0; j--) { // decrement j until 0
			if ((*s)[j + k - 1]->isPair)
				insert(S, (*s)[j + k - 1]->pair.second, j + k);
			else
				insert(S, (*s)[j + k - 1]->pair.first, j + k - 1);
		}
		k += i;
	}
}

void	pMergeMe(std::vector<Object*> *S)
{
	std::vector<Object *>	s;

	size_t j = 0;

	// put an alfe inside x, and other alfe inside y, if 1 remain, put inside y
	for (std::vector<Object*>::iterator it = S->begin(); it != S->end(); it++) {
		if ((it - S->begin()) % 2 == 0) {
			Object *tmp = new Object;
			tmp->pair.first = *it;
			tmp->x = (*it)->x;
			s.push_back(tmp);
		}
		else
		{
			s[j]->pair.second = *it;
			s[j]->y = (*it)->x;
			s[j++]->isPair = true;
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
	

	for (std::vector<long long>::iterator it = S->begin(); it != S->end(); it++) {
		Object *tmp = new Object;
		tmp->x = *it;
		s.push_back(tmp);
	}

	// sorte s with Merge-insertion sort
	pMergeMe(&s);

	// convert s to S
	for (std::vector<Object*>::iterator it = s.begin(); it != s.end(); it++)
		(*S)[it - s.begin()] = (*it)->x;

	for (std::vector<Object*>::iterator it = s.begin(); it != s.end(); it++)
		delete *it;
}
