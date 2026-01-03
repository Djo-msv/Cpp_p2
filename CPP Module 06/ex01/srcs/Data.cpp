#include "Data.hpp"

Data::Data(void)
{}

Data::Data(const Data &value)
{
	(void)value;
}

Data::~Data()
{}

Data &Data::operator=(const Data &value)
{
	(void)value;
	return *this;
}
