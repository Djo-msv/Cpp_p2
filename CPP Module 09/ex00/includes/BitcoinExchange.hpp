#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>

#ifndef VERBOSE
# define VERBOSE 0
#endif

#define INT16_MAX 32767
#define INT16_MIN -32768

struct	date_s {
	short	year;
	char	month;
	char	day;
};

void	setupPrimaryDb(std::map<date_s, double> *primaryDb);
void	manageSecondDb(std::map<date_s, double> *primaryDb, const char *path);
