#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

struct	Object {
	long long			x;
	long long			y;
	std::pair<Object *, Object *>	pair;
	bool				isPair;

	void	swap();
};

void	pMergeMeSetup(std::vector<long long> *S);
