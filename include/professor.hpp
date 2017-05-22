#ifndef PROFESSORHPP
#define PROFESSORHPP

#include "common.hpp"

class professor{
public:
	int id;
	array<int,5> preferencia;
	int nDeHabilitacoes;

	professor(){};
	professor(int i,const array<int,5>& pref,int n);
};

std::ostream& operator<<(std::ostream& os,const professor& e);


using mapProf=map<int,professor>;

#endif//PROFESSORHPP