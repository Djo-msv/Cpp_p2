#include "Base.hpp"
#include "IdentifyRealType.hpp"

int	main(void)
{

	std::cout << "===== | pointer | =====" << std::endl;

	for (int i = 0; i != 100; i++)
	{
		Base *value = generate();
		identify(value);
		delete value;
	}

	std::cout << std::endl << "===== | reference | =====" << std::endl;
	
	for (int i = 0; i != 100; i++)
	{
		Base *value = generate();
		identify(&(*value));
		delete value;
	}
	return (0);
}
