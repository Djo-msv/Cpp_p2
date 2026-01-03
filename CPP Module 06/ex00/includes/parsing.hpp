#pragma once

#include <string>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int	is_int(std::string &value);
int is_char(std::string *value);
int	is_float(std::string &value);
int	is_double(std::string &value);
int	is_exeption(std::string &value);
