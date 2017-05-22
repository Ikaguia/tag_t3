#ifndef PROFESSORHPP
#define PROFESSORHPP

#include "common.hpp"
#include "escola.hpp"

class professor{
public:
	int id;
	array<int,5> preferencia;
	int nivel;

	professor(){};
	professor(int i,const array<int,5>& pref,int n);

	void removePreferenciasMenores(int id);
	bool prefere(int escola,int escolaAtual);
};

std::ostream& operator<<(std::ostream& os,const professor& e);


using mapProf=map<int,professor>;

#endif//PROFESSORHPP