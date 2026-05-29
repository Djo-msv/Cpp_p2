#include "Data.hpp"

Data::Data(void)
{
	_value = 0;
}

Data::Data(const Data &value)
{
	_value = value._value;
}

Data::~Data()
{}

Data &Data::operator=(const Data &value)
{
	_value = value._value;
	return *this;
}
