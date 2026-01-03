#include "Data.hpp"
#include "Serialization.hpp"

int	main()
{
	Data *d = new Data();

	uintptr_t value = Serializer::serialize(d);
	std::cout << "ptr1: " << value << std::endl;
	std::cout << "ptr2: " << Serializer::serialize(Serializer::deserialize(value)) << std::endl;
	delete d;
}
