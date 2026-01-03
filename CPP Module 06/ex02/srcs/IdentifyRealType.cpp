#include "IdentifyRealType.hpp"

Base *generate(void)
{
	int			i;
	static bool	setTime = false;

	if (!setTime)
	{
		srand((unsigned)time(0));
		setTime = true;
	}
	i = (rand() % 3);
	std::cout << "i = " << i << " | ";
	switch (i)
	{
		case 0: return (new A());
		case 1: return (new B());
		case 2: return (new C());
		default: return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "value: A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "value: B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "value: C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A tmp = dynamic_cast<A&>(p);
		std::cout << "value: A" << std::endl;
		return ;
	}
	catch (std::exception exp)
	{}
	try
	{
		B tmp = dynamic_cast<B&>(p);
		std::cout << "value: B" << std::endl;
		return ;
	}
	catch (std::exception exp)
	{}
	try
	{
		C tmp = dynamic_cast<C&>(p);
		std::cout << "value: C" << std::endl;
		return ;
	}
	catch (std::exception exp)
	{}
}
