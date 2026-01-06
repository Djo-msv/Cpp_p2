#include "iter.hpp"

void	display(const int &value)
{
	std::cout << "value = " << value << std::endl;
}

int	main(void)
{
	int tab[131];

	for (int i = 0; i != 131; i++)
		tab[i] = i;
	iter(tab, 131, &display);
}
