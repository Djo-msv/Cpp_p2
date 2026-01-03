#pragma once

class Data
{
	public :
		Data();
		Data(const Data &value);
		~Data();

		Data &operator=(const Data &value);
};
