#ifndef ESCOLAHPP
#define ESCOLAHPP

#include "common.hpp"

class escola{
public:
	int id;
	int preferencia;

	escola(){};
	escola(int i,int pref);
};

std::ostream& operator<<(std::ostream& os,const escola& e);

#endif//ESCOLAHPP