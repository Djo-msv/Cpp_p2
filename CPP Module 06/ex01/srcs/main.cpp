#include "Data.hpp"
#include "Serialization.hpp"

int	main()
{
	Data *a = new Data();
	Data *b;

	uintptr_t value = Serializer::serialize(a);
	a->_value = 10;
	std::cout << "ptr1: " << value << std::endl;
	std::cout << "ptr2: " << Serializer::serialize(Serializer::deserialize(value)) << std::endl;
	b = Serializer::deserialize(value);
	std::cout << "value : " << b->_value << std::endl;
	delete a;
}
