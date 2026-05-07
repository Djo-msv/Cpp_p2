#pragma once

struct	Object {
	bool				isPair;
	long long			x;
	std::pair<Object *, Object *>	pair;

	void	setupPair(Object *node);
};
