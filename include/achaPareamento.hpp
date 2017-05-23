#ifndef ACHAPAREAMENTOHPP
#define ACHAPAREAMENTOHPP

#include "common.hpp"
#include "professor.hpp"
#include "escola.hpp"

void achaPareamento(mapProf &professores,mapEsc &escolas,map<int,int> &parPE,map<int,ii> &parEP);

void associa(map<int,int> &parPE,map<int,ii> &parEP,int escola,int professor);

void desassocia(map<int,int> &parPE,map<int,ii> &parEP,int escola,int professor);

bool escolaPrefere(int escola,int novoProf,mapEsc &escolas,mapProf &professores,int professor);

#endif//ACHAPAREAMENTOHPP