#include "PmergeMe.hpp"

void	sortPair(std::vector<Object*> *S)
{
	for (size_t i = 0; (*S)[i]; i++) {
		if ((*S)[i]->x < [*S][i]->y)
			(*S)[i]->swap();
}

void	insert(std::vector<Object*> *S, std::vector<Object *> *s)
{
	size_t	i = 0;
	size_t	j = 0;

	S.clear();
	for (size_t iterator = 1; !s.empty(); iterator++) {
		j = pow(2, iterator) - i;
		i = j;

		if (j)
	}

}

void	pMergeMe(std::vector<Object*> *S)
{
	std::vector<Object *>	s;

	// put an alfe inside x, and other alfe inside y, if 1 remain, put inside y
	for (size_t i = 0, size_t j = 0; (*S)[i]; i++) {
		if (i % 2) {
			s[j]->pair.first = S[i];
			s[j]->x = S[i]->x;
		}
		else
		{
			s[j]->pair.second = S[i];
			s[j++]->y = S[i]->y;
		}

	}
	
	// sort pair to make x > y;
	sortPair(&s);

	// recurisivity. so x is sorted
	pMergeMe(&s);

	// insertion of y inside x, and put result insde S
	insert(S, &s);
}

void	pMergeMeSetup(std::vector<long long> &S)
{
	std::vector<Object *>	s;

	// convert S to s
	for (size_t i = 0; (*S)[i]; i++)
		s[i] = (&Object)->x = ((*S)[i]);

	// sorte s with Merge-insertion sort
	pMergeMe(&s);

	// convert s to S
	for (size_t j = 0; s[j]; j++)
		*S[j] = s[j].x;
}
