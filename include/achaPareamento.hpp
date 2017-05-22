#ifndef ACHAPAREAMENTOHPP
#define ACHAPAREAMENTOHPP

#include "common.hpp"
#include "professor.hpp"
#include "escola.hpp"

void achaPareamento(mapProf &professores,mapEsc &escolas,map<int,int> &parPE,map<int,ii> &parEP);

void associa(map<int,int> &parPE,map<int,ii> &parEP,int escola,int professor);

void desassocia(map<int,int> &parPE,map<int,ii> &parEP,int escola,int professor);

bool escolaPrefere(int nivel,ii niveisAtuais,escola& escola);

#endif//ACHAPAREAMENTOHPP